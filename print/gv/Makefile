# $NetBSD: Makefile,v 1.68 2008/11/10 17:21:37 wiz Exp $

DISTNAME=	gv-3.6.3
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU:=gv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gv/
COMMENT=	PostScript and PDF previewer

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gs:run makeinfo

TEXINFO_REQD=		4.2
INFO_FILES=		yes
LIBS+=			${BUILDLINK_LDADD.getopt}

# this pkg does not work with std xaw, but xpm and xaw3d work
XAW_TYPE?=		3d
.include "../../mk/bsd.prefs.mk"
.if ${XAW_TYPE} == "standard"
XAW_TYPE=		3d
.endif

# Solaris-2.{8,9}/sparc are missing setenv() and unsetenv()
# it is probably true that 5.6, 5.7, 5.8, and 5.9 all have
# this problem.  It appears that 5.10 does not need this flag.
.if ${OPSYS} == "SunOS" && !empty(OS_VERSION:M5.[6789])
CONFIGURE_ARGS+=	--enable-setenv-code
.endif

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
