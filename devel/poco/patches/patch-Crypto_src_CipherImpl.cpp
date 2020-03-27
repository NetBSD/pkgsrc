$NetBSD: patch-Crypto_src_CipherImpl.cpp,v 1.1 2020/03/27 02:08:11 joerg Exp $

--- Crypto/src/CipherImpl.cpp.orig	2020-03-27 00:11:42.909559121 +0000
+++ Crypto/src/CipherImpl.cpp
@@ -77,7 +77,7 @@ namespace
 
 	private:
 		const EVP_CIPHER* _pCipher;
-		EVP_CIPHER_CTX    _ctx;
+		EVP_CIPHER_CTX    *_ctx;
 		ByteVec           _key;
 		ByteVec           _iv;
 	};
@@ -92,9 +92,10 @@ namespace
 		_key(key),
 		_iv(iv)
 	{
-		EVP_CipherInit(
-			&_ctx,
-			_pCipher,
+		_ctx = EVP_CIPHER_CTX_new();
+		EVP_CipherInit_ex(
+			_ctx,
+			_pCipher, NULL,
 			&_key[0],
 			_iv.empty() ? 0 : &_iv[0],
 			(dir == DIR_ENCRYPT) ? 1 : 0);
@@ -103,19 +104,19 @@ namespace
 
 	CryptoTransformImpl::~CryptoTransformImpl()
 	{
-		EVP_CIPHER_CTX_cleanup(&_ctx);
+		EVP_CIPHER_CTX_free(_ctx);
 	}
 
 
 	std::size_t CryptoTransformImpl::blockSize() const
 	{
-		return EVP_CIPHER_CTX_block_size(&_ctx);
+		return EVP_CIPHER_CTX_block_size(_ctx);
 	}
 
 	
 	int CryptoTransformImpl::setPadding(int padding)
 	{
-		return EVP_CIPHER_CTX_set_padding(&_ctx, padding);
+		return EVP_CIPHER_CTX_set_padding(_ctx, padding);
 	}
 	
 
@@ -129,7 +130,7 @@ namespace
 
 		int outLen = static_cast<int>(outputLength);
 		int rc = EVP_CipherUpdate(
-			&_ctx,
+			_ctx,
 			output,
 			&outLen,
 			input,
@@ -153,7 +154,7 @@ namespace
 		// Use the '_ex' version that does not perform implicit cleanup since we
 		// will call EVP_CIPHER_CTX_cleanup() from the dtor as there is no
 		// guarantee that finalize() will be called if an error occurred.
-		int rc = EVP_CipherFinal_ex(&_ctx, output, &len);
+		int rc = EVP_CipherFinal_ex(_ctx, output, &len);
 
 		if (rc == 0)
 			throwError();
