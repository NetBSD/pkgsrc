# $NetBSD: openssl.mk,v 1.1 2007/09/18 03:18:23 smb Exp $
#

# for SMTP, POP3 and IMAP over SSL
# set these just in case we don't have a pkg-config file for openssl
CONFIGURE_ENV+=		OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.openssl}/include"
CONFIGURE_ENV+=		OPENSSL_LIBS="-L${BUILDLINK_PREFIX.openssl}/lib -lssl -lcrypto"
