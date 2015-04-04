# $NetBSD: Makefile,v 1.1 2015/04/04 12:54:07 rodent Exp $

GITHUB_PROJECT=	jimtcl
DISTNAME=	0.76
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=msteveb/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://jim.tcl.tk/
COMMENT=	Small footprint implementation of the Tcl programming language
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/jimtcl-0.76
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q} --exec-prefix=${PREFIX:Q}

REPLACE_INTERPRETER+=	jimsh
REPLACE.jimsh.old=	/usr/bin/env jimsh
REPLACE.jimsh.new=	${PREFIX}/bin/jimsh
REPLACE_FILES.jimsh=	build-jim-ext.in

SUBST_CLASSES+=		docdir
SUBST_FILES.docdir=	Makefile.in
SUBST_MESSAGE.docdir=	Fixing path to docdir.
SUBST_SED.docdir=	-e 's|$(prefix)/doc/jim|$(prefix)/share/doc/jimtcl|g'
SUBST_STAGE.docdir=	pre-configure

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
