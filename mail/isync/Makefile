# $NetBSD: Makefile,v 1.3 2003/12/27 16:54:06 seb Exp $
#

DISTNAME=	isync-0.9.2
CATEGORIES=	mail net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isync/}

MAINTAINER=	cez+misc.pkgsrc@compsoc.man.ac.uk
HOMEPAGE=	http://isync.sourceforge.net/
COMMENT=	Syncronize a maildir with an imap server

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
LDFLAGS+=		-lcrypto

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/isync
	${INSTALL_DATA} ${WRKSRC}/isyncrc.sample ${PREFIX}/share/examples/isync/isyncrc.sample

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
