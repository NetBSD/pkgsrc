# $NetBSD: Makefile,v 1.28 2011/12/21 14:24:32 wiz Exp $
#

DISTNAME=	p0f-2.0.8
CATEGORIES=	security net
MASTER_SITES=	http://lcamtuf.coredump.cx/p0f/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lcamtuf.coredump.cx/p0f.shtml
COMMENT=	Passive OS fingerprinting tool
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/p0f

PKG_SYSCONFSUBDIR=	p0f

MAKE_ENV+=	LIBPCAP_PREFIX=${BUILDLINK_PREFIX.libpcap}

CONF_FILES=	${PREFIX}/share/examples/p0f/p0f.fp ${PKG_SYSCONFDIR}/p0f.fp
CONF_FILES+=	${PREFIX}/share/examples/p0f/p0fa.fp ${PKG_SYSCONFDIR}/p0fa.fp
CONF_FILES+=	${PREFIX}/share/examples/p0f/p0fr.fp ${PKG_SYSCONFDIR}/p0fr.fp

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	config.h p0f.1
SUBST_SED.paths=	-e "s|/etc/p0f|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.paths=	Fixing paths.

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/p0f share/examples/p0f

post-patch:
	${LN} -s NetBSD ${WRKSRC}/mk/DragonFly

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p0f ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${PREFIX}/share/doc/p0f/p0f.README
	${INSTALL_DATA} ${WRKSRC}/p0frep ${DESTDIR}${PREFIX}/share/doc/p0f/p0frep
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${DESTDIR}${PREFIX}/share/examples/p0f
	${INSTALL_DATA} ${WRKSRC}/p0fa.fp ${DESTDIR}${PREFIX}/share/examples/p0f
	${INSTALL_DATA} ${WRKSRC}/p0fr.fp ${DESTDIR}${PREFIX}/share/examples/p0f
	${INSTALL_MAN} ${WRKSRC}/p0f.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
