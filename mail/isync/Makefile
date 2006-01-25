# $NetBSD: Makefile,v 1.16 2006/01/25 17:35:49 tonio Exp $
#

DISTNAME=	isync-1.0.1
PKGREVISION=	3
CATEGORIES=	mail net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isync/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://isync.sourceforge.net/
COMMENT=	Synchronize a maildir with an imap server

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
LDFLAGS+=		-lcrypto

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/isync
	${INSTALL_DATA} ${WRKSRC}/src/mbsyncrc.sample \
		${PREFIX}/share/examples/isync/mbsyncrc.sample
	${INSTALL_DATA} ${WRKSRC}/src/compat/isyncrc.sample \
		${PREFIX}/share/examples/isync/isyncrc.sample

.include "../../mk/bsd.pkg.mk"
