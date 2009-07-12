# $NetBSD: Makefile,v 1.25 2009/07/12 20:26:59 tonio Exp $
#

DISTNAME=	isync-1.0.4
CATEGORIES=	mail net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isync/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://isync.sourceforge.net/
COMMENT=	Synchronize a maildir with an imap server

LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
INSTALLATION_DIRS+=	share/examples/isync
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
LDFLAGS+=		-lcrypto

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/mbsyncrc.sample \
		${DESTDIR}${PREFIX}/share/examples/isync/mbsyncrc.sample
	${INSTALL_DATA} ${WRKSRC}/src/compat/isyncrc.sample \
		${DESTDIR}${PREFIX}/share/examples/isync/isyncrc.sample

.include "../../mk/bsd.pkg.mk"
