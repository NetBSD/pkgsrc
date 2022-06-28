# $NetBSD: Makefile,v 1.27 2022/06/28 11:31:41 wiz Exp $

DISTNAME=		cogito-0.18.2
PKGREVISION=		14
CATEGORIES=		devel
MASTER_SITES=		http://www.kernel.org/pub/software/scm/cogito/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://git.or.cz/cogito/
COMMENT=		Version control system of the Linux kernel

DEPENDS+=		git-[0-9]*:../../devel/git

USE_TOOLS+=		gmake bash:run perl:run
USE_TOOLS+=		fgrep:run grep:run mktemp:run xargs:run
MAKE_FLAGS+=		prefix=${PREFIX:Q}

REPLACE_BASH+=		cg cg-Xlib cg-Xmergefile cg-add cg-admin-cat
REPLACE_BASH+=		cg-admin-ls cg-admin-lsobj cg-admin-rewritehist
REPLACE_BASH+=		cg-admin-setuprepo cg-admin-uncommit cg-branch-add
REPLACE_BASH+=		cg-branch-chg cg-branch-ls cg-clean cg-clone
REPLACE_BASH+=		cg-commit cg-diff cg-export cg-fetch cg-help cg-init
REPLACE_BASH+=		cg-log cg-merge cg-mkpatch cg-mv cg-object-id cg-patch
REPLACE_BASH+=		cg-push cg-reset cg-restore cg-rm cg-seek cg-status
REPLACE_BASH+=		cg-switch cg-tag cg-tag-ls cg-tag-show cg-update
REPLACE_BASH+=		cg-version.in

REPLACE_PERL+=		cg-Xfetchprogress
REPLACE_PERL+=		cg-Xfollowrenames


.include "../../mk/bsd.prefs.mk"

# we need gnu-ish versions of these.  In particular, we require
# that grep accept -q and xargs accept -0
.if ${OPSYS} == "SunOS"

DEPENDS+=		findutils>=4.1:../../sysutils/findutils
TOOLS_PLATFORM.xargs=	${LOCALBASE}/bin/gxargs

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
