# $NetBSD: Makefile,v 1.28 2008/01/18 05:08:26 tnn Exp $
#

DISTNAME=	mailsync_5.2.1.orig
PKGNAME=	mailsync-5.2.1
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailsync/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mailsync.sourceforge.net/
COMMENT=	Mailsync is a way of synchronizing a collection of mailboxes

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}/include
CONFIGURE_ARGS+=	--with-c-client=${BUILDLINK_DIR}/include/c-client
CONFIGURE_ARGS+=	--without-krb5

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	configure doc/examples/mailsync doc/mailsync.1
SUBST_SED.conf=		-e "s|@BUILDLINK_DIR@|${BUILDLINK_DIR}|g" \
			-e "s|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g" \
			-e "s|/usr/share|${PREFIX}/share|g"
SUBST_MESSAGE.conf=	Fixing configure script.

DOCS=	COPYING NEWS README THANKS TODO doc/ABSTRACT doc/HACKING

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mailsync
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mailsync
	${INSTALL_PROGRAM} ${WRKSRC}/src/mailsync ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/examples/mailsync \
		${PREFIX}/share/examples/mailsync/dot.mailsync
	${INSTALL_MAN} ${WRKSRC}/doc/mailsync.1 ${PREFIX}/${PKGMANDIR}/man1
.for d in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${d} ${PREFIX}/share/doc/mailsync
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/imap-uw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
