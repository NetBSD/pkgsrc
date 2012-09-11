# $NetBSD: Makefile,v 1.19 2012/09/11 23:19:33 asau Exp $

DISTNAME=		autoswc-1.6
CATEGORIES=		pkgtools sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		jmmv@NetBSD.org
COMMENT=		Generates system wide cache files for GNU autoconf

DEPENDS+=		autoconf>=2.59:../../devel/autoconf
DEPENDS+=		automake>=1.8.2:../../devel/automake
DEPENDS+=		libtool-base>=1.5.2:../../devel/libtool-base

NO_CONFIGURE=		YES
WRKSRC=			${WRKDIR}

PKG_SYSCONFSUBDIR=	autoswc
CACHEDIR=		/var/db/autoswc
MKCONF=			/etc/mk.conf
OWN_DIRS=		${CACHEDIR}

EVAL_PREFIX+=			PREFIX.autoconf=autoconf
PREFIX.autoconf_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=			PREFIX.automake=automake
PREFIX.automake_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=			PREFIX.libtool=libtool
PREFIX.libtool_DEFAULT=		${LOCALBASE}

SUBST_CLASSES+=		build
SUBST_MESSAGE.build=	Building autoswc.
SUBST_STAGE.build=	do-build
SUBST_FILES.build=	autoswc
SUBST_FILES.build+=	autoswc.8
SUBST_FILES.build+=	autoswc.mk
SUBST_FILES.build+=	config.site
SUBST_SED.build=	-e 's|@ACLOCAL@|${PREFIX.automake}/bin/aclocal|g'
SUBST_SED.build+=	-e 's|@AUTOCONF@|${PREFIX.autoconf}/bin/autoconf|g'
SUBST_SED.build+=	-e 's|@AUTOMAKE@|${PREFIX.automake}/bin/automake|g'
SUBST_SED.build+=	-e 's|@CACHEDIR@|${CACHEDIR}|g'
SUBST_SED.build+=	-e 's|@LIBTOOLIZE@|${PREFIX.libtool}/bin/libtoolize|g'
SUBST_SED.build+=	-e 's|@MACHINE_GNU_PLATFORM@|${MACHINE_GNU_PLATFORM}|g'
SUBST_SED.build+=	-e 's|@MAKE@|${MAKE}|g'
SUBST_SED.build+=	-e 's|@MKCONF@|${MKCONF}|g'
SUBST_SED.build+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.build+=	-e 's|@SH@|${SH}|g'
SUBST_SED.build+=	-e 's|@SYSCONFDIR@|${PKG_SYSCONFDIR}|g'

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/autoswc

do-extract:
	${CP} ${FILESDIR}/autoswc.8 ${WRKSRC}
	${CP} ${FILESDIR}/autoswc.mk ${WRKSRC}
	${CP} ${FILESDIR}/autoswc.sh ${WRKSRC}/autoswc
	${CP} ${FILESDIR}/config.site ${WRKSRC}

do-build:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/autoswc ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/autoswc.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/autoswc.mk ${DESTDIR}${PREFIX}/share/autoswc
	${INSTALL_DATA} ${WRKSRC}/config.site ${DESTDIR}${PREFIX}/share/autoswc
	${INSTALL_DATA} ${FILESDIR}/configure.ac ${DESTDIR}${PREFIX}/share/autoswc

.include "../../mk/bsd.pkg.mk"
