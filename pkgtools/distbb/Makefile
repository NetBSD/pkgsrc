# $NetBSD: Makefile,v 1.2 2011/08/08 10:05:21 cheusov Exp $
#

DISTNAME=	distbb-0.40.1
CATEGORIES=	pkgtools
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/cheusov/distbb/ \
		http://mova.org/~cheusov/pub/distbb/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://mova.org/~cheusov/pub/distbb/
COMMENT=	DISTributed Bulk Build tool for pkgsrc
LICENSE=	2-clause-bsd

DEPENDS+=	pkg_summary-utils>=0.53:../../pkgtools/pkg_summary-utils
DEPENDS+=	paexec>=0.16.0:../../parallel/paexec
DEPENDS+=	runawk>=1.1.0:../../lang/runawk
DEPENDS+=	pipestatus>=0.6.0:../../devel/pipestatus
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest

BUILD_DEPENDS+=	mk-configure>=0.21:../../devel/mk-configure

USE_LANGUAGES=		# none

REPLACE_SH+=		distbb.in distbb_diff.in slave.in stage_*.in

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	/usr/bin/env runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	gen_weights.in gen_queue.in

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			${PREFIX}/share/examples/distbb
DOCDIR=			${PREFIX}/share/doc/distbb

CONF_FILES=		${EGDIR}/distbb.conf     ${PKG_SYSCONFDIR}/distbb.conf
CONF_FILES+=		${EGDIR}/distbb.local.mk ${PKG_SYSCONFDIR}/distbb.local.mk

DOCFILES=		README NEWS TODO

MAKE_FLAGS+=		EGDIR=${EGDIR}

AUTO_MKDIRS=		yes

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

MAKE_PROGRAM=		mkcmake

.include "../../mk/bsd.pkg.mk"
