# $NetBSD: Makefile,v 1.12 2009/09/03 10:01:45 wiz Exp $
#

DISTNAME=		cogito-0.18.2
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://www.kernel.org/pub/software/scm/cogito/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://git.or.cz/cogito/
COMMENT=		Version control system of the Linux kernel

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		scmgit-[0-9]*:../../devel/scmgit

USE_TOOLS+=		gmake bash:run fgrep:run grep:run mktemp:run xargs:run
MAKE_FLAGS+=		prefix=${PREFIX:Q}

.include "../../mk/bsd.prefs.mk"

# we need gnu-ish versions of these.  In particular, we require
# that grep accept -q and xargs accept -0
.if ${OPSYS} == "SunOS"

DEPENDS+=	findutils>=4.1:../../sysutils/findutils
TOOLS_PLATFORM.xargs=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}xargs

.endif

post-patch:
	for f in ${WRKSRC}/cg* ; do \
		${MV} $$f $$f.bak ;  \
		${SED} -e 's;\([ 	]\)fgrep\([ 	]\);\1${FGREP}\2;g' \
			-e 's;\([ 	]\)grep\([ 	]\);\1${GREP}\2;' \
			-e 's;\([ 	]\)xargs\([ 	]\);\1${XARGS}\2;g' \
			$$f.bak > $$f ; \
		${CHMOD} a+x $$f ; \
	done


.include "../../mk/bsd.pkg.mk"
