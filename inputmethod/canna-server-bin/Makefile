# $NetBSD: Makefile,v 1.3 2002/12/02 03:40:21 itojun Exp $

DISTNAME=	Canna35b2
PKGNAME=	Canna-server-bin-3.5.2
PKGREVISION=	3
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna35/

PATCH_SITES=	http://www.jaist.ac.jp/~fujieda/canna/
PATCHFILES=	Canna35b2-unoff1.patch.gz Canna35b2-unoff2.patch.gz \
		Canna35b2-hack1.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.nec.co.jp/japanese/product/computer/soft/canna/
COMMENT=	Kana-Kanji conversion system (server binary)

FILESDIR=	${.CURDIR}/../canna-lib/files
DISTINFO_FILE=	${.CURDIR}/../canna-lib/distinfo
PATCHDIR=	${.CURDIR}/../canna-lib/patches

BUILD_DEFS+=	USE_INET6

USE_BUILDLINK2=	YES

.include "../../mk/bsd.prefs.mk"
.if 0	# ${USE_INET6} == "YES"
INET6=		-DINET6
.else
INET6=		# empty
.endif
CANNAOWNER?=	daemon
CANNAGROUP?=	daemon
CANNA_SPOOL=	/var/spool/canna
CANNA_MODE=	0755
MAKE_ENV+=	CANNAOWNER=${CANNAOWNER} CANNAGROUP=${CANNAGROUP} \
		CANNA_SPOOL=${CANNA_SPOOL} IMDICTDIR=${IMDICTDIR} INET6=${INET6}
PLIST_SUBST+=	CANNAOWNER=${CANNAOWNER} CANNAGROUP=${CANNAGROUP} \
		CANNA_SPOOL=${CANNA_SPOOL} CANNA_MODE=${CANNA_MODE}

INSTALL_TARGET=	instserver

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	${SED} -e 's|\(SUBDIRS = \).*|\1 canna lib server cmd doc|' \
		-e 's|\(SERVERDIR = \).*|\1 server cmd doc|' \
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile
	${MV} ${WRKSRC}/Canna.conf ${WRKSRC}/Canna.conf.orig
	${SED} -e 's|\(DicDir.*=\).*|\1${IMDICTDIR}/canna|' \
		${WRKSRC}/Canna.conf.orig > ${WRKSRC}/Canna.conf

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF})

post-build:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/canna \
		> ${WRKDIR}/canna

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
	@${INSTALL_SCRIPT} ${WRKDIR}/canna ${PREFIX}/etc/rc.d/canna
	@${INSTALL_DATA_DIR} ${CANNA_SPOOL}
	@${CHMOD} ${CANNA_MODE} ${CANNA_SPOOL}
	@${CHOWN} ${CANNAOWNER}:${CANNAGROUP} ${CANNA_SPOOL}

.include "../../devel/nbitools/buildlink2.mk"
.include "../../inputmethod/canna-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
