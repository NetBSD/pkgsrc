# $NetBSD: Makefile,v 1.4 2002/12/27 08:41:25 uebayasi Exp $

DISTNAME=	Canna36p1
PKGNAME=	Canna-server-bin-3.6.1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://downloads.sourceforge.jp/canna/1722/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://canna.sourceforge.jp/
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
