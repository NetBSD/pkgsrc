$NetBSD: patch-eccrypto.cpp,v 1.1 2012/12/22 02:29:36 joerg Exp $

--- eccrypto.cpp.orig	2012-12-21 21:44:36.000000000 +0000
+++ eccrypto.cpp
@@ -389,7 +389,7 @@ template <class EC> void DL_GroupParamet
 	StringSource ssG(param.g, true, new HexDecoder);
 	Element G;
 	bool result = GetCurve().DecodePoint(G, ssG, (size_t)ssG.MaxRetrievable());
-	SetSubgroupGenerator(G);
+	this->SetSubgroupGenerator(G);
 	assert(result);
 
 	StringSource ssN(param.n, true, new HexDecoder);
@@ -545,7 +545,7 @@ bool DL_GroupParameters_EC<EC>::Validate
 	if (level >= 2 && pass)
 	{
 		const Integer &q = GetSubgroupOrder();
-		Element gq = gpc ? gpc->Exponentiate(this->GetGroupPrecomputation(), q) : ExponentiateElement(g, q);
+		Element gq = gpc ? gpc->Exponentiate(this->GetGroupPrecomputation(), q) : this->ExponentiateElement(g, q);
 		pass = pass && IsIdentity(gq);
 	}
 	return pass;
@@ -583,7 +583,7 @@ void DL_PublicKey_EC<EC>::BERDecodePubli
 	typename EC::Point P;
 	if (!this->GetGroupParameters().GetCurve().DecodePoint(P, bt, size))
 		BERDecodeError();
-	SetPublicElement(P);
+	this->SetPublicElement(P);
 }
 
 template <class EC>
