# $NetBSD: Makefile,v 1.2 2016/07/01 17:55:23 jperkin Exp $

VERSION=	1.5.4
DISTNAME=	${VERSION}
PKGNAME=	pkg-${VERSION}
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=freebsd/pkg/archive/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://wiki.freebsd.org/pkgng
COMMENT=	Package management tool for FreeBSD
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/pkg-${VERSION}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf
USE_TOOLS+=	automake
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CPPFLAGS+=	-D_LOCALBASE="\"${PREFIX}\""
CPPFLAGS+=	-DPORTSDIR="\"/usr/pkgsrc\""

AUTO_MKDIRS=	yes

EGDIR=		${PREFIX}/share/examples/pkg

CONF_FILES+=	${EGDIR}/bash_completion.d/_pkg.bash \
		${PKG_SYSCONFDIR}/bash_completion.d/_pkg.bash
CONF_FILES+=	${EGDIR}/periodic/daily/411.pkg-backup \
		${PKG_SYSCONFDIR}/periodic/daily/411.pkg-backup
CONF_FILES+=	${EGDIR}/periodic/daily/490.status-pkg-changes \
		${PKG_SYSCONFDIR}/periodic/daily/490.status-pkg-changes
CONF_FILES+=	${EGDIR}/periodic/security/410.pkg-audit \
		${PKG_SYSCONFDIR}/periodic/security/410.pkg-audit
CONF_FILES+=	${EGDIR}/periodic/security/460.pkg-checksum \
		${PKG_SYSCONFDIR}/periodic/security/460.pkg-checksum
CONF_FILES+=	${EGDIR}/periodic/weekly/400.status-pkg \
		${PKG_SYSCONFDIR}/periodic/weekly/400.status-pkg
CONF_FILES+=	${EGDIR}/pkg.conf.sample \
		${PKG_SYSCONFDIR}/pkg.conf

SUBST_CLASSES+=	manpages-prefix
SUBST_STAGE.manpages-prefix=	pre-install
SUBST_FILES.manpages-prefix=	docs/pkg-install.8 docs/pkg-repo.8
SUBST_FILES.manpages-prefix+=	docs/pkg-search.8 docs/pkg-update.8
SUBST_FILES.manpages-prefix+=	docs/pkg-upgrade.8 docs/pkg.8
SUBST_FILES.manpages-prefix+=	docs/pkg.conf.5
SUBST_SED.manpages-prefix+=	-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.manpages-prefix=	Correct the installation prefix in manual pages.

SUBST_CLASSES+=	pkgconf-prefix
SUBST_STAGE.pkgconf-prefix=	pre-install
SUBST_FILES.pkgconf-prefix=	src/pkg.conf.sample
SUBST_SED.pkgconf-prefix+=	-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.pkgconf-prefix=	Correct the installation prefix in pkg.conf(5).

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/bash_completion.d/_pkg.bash \
		${DESTDIR}${EGDIR}/bash_completion.d/_pkg.bash
	${RMDIR} ${DESTDIR}${PREFIX}/etc/bash_completion.d
	${MV} ${DESTDIR}${PREFIX}/etc/periodic/daily/411.pkg-backup \
		${DESTDIR}${EGDIR}/periodic/daily/411.pkg-backup
	${MV} ${DESTDIR}${PREFIX}/etc/periodic/daily/490.status-pkg-changes \
		${DESTDIR}${EGDIR}/periodic/daily/490.status-pkg-changes
	${RMDIR} ${DESTDIR}${PREFIX}/etc/periodic/daily
	${MV} ${DESTDIR}${PREFIX}/etc/periodic/security/410.pkg-audit \
		${DESTDIR}${EGDIR}/periodic/security/410.pkg-audit
	${MV} ${DESTDIR}${PREFIX}/etc/periodic/security/460.pkg-checksum \
		${DESTDIR}${EGDIR}/periodic/security/460.pkg-checksum
	${RMDIR} ${DESTDIR}${PREFIX}/etc/periodic/security
	${MV} ${DESTDIR}${PREFIX}/etc/periodic/weekly/400.status-pkg \
		${DESTDIR}${EGDIR}/periodic/weekly/400.status-pkg
	${RMDIR} ${DESTDIR}${PREFIX}/etc/periodic/weekly
	${MV} ${DESTDIR}${PREFIX}/etc/pkg.conf.sample \
		${DESTDIR}${EGDIR}/pkg.conf.sample

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
