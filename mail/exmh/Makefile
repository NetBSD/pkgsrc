# $NetBSD: Makefile,v 1.12 1998/08/14 07:45:26 tron Exp $
# FreeBSD Id: Makefile,v 1.25 1998/02/15 05:36:54 peter Exp
#

DISTNAME=	exmh-2.0.2
CATEGORIES=	mail tk80
MASTER_SITES=	http://sunscript.sun.com/dist/
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	http://sunscript.sun.com/exmh/patches/2.0.1/

.include "../../mk/bsd.prefs.mk"

# User contributed and "new features".  Some not useable as-is.
PATCHFILES+=	seditpost.patch inc.patch next.patch
# XXX pgpExec.patch has got confused paths	(supplied as patch-as)
# XXX newsgroups.patch is relative to a different directory (patch-at)
# XXX MDN.patch doesn't apply			(patch-au)
# XXX post.from.patch doesn't apply		(patch-av)
.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS= -d ${WRKSRC}/lib -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS= -d ${WRKSRC}/lib --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	tclsh8.0:../../lang/tcl80
RUN_DEPENDS=	wish8.0:../../x11/tk80
# exmh is pretty useless without this, but it's not needed to build it.
RUN_DEPENDS+=   repl:../../mail/nmh
# full mime support needs mmencode/mmdecode from metamail
RUN_DEPENDS+=   mmencode:../../mail/metamail

DIST_SUBDIR=	${PKGNAME}

WISH=		wish8.0
TCLSH=		tclsh8.0

# Additionally, exmh will use the following ports if present:
# lang/expect
# textproc/glimpse
# security/pgp
# mail/faces
# audio/rplay

do-build:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} TCLSH=${TCLSH} \
		WISH=${PREFIX}/bin/${WISH} WRKSRC=${WRKSRC} \
		FILESDIR=${FILESDIR} ${SH} ${SCRIPTDIR}/build

do-install:
	@cd ${WRKSRC} && ${SETENV} PREFIX=${PREFIX} \
		WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/install

.include "../../mk/bsd.pkg.mk"
