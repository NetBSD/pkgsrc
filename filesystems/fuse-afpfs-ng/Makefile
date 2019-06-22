# $NetBSD: Makefile,v 1.15 2019/06/22 11:52:31 nia Exp $

DISTNAME=	afpfs-ng-0.8.1
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=afpfs-ng/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/afpfs-ng
COMMENT=	FUSE filesystem for network mounting using AFP

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

REPLACE_SH+=	fuse/afpfs

.include "../../mk/readline.buildlink3.mk"

SUBST_CLASSES+=		termcap
SUBST_STAGE.termcap=	pre-configure
SUBST_FILES.termcap=	configure.ac configure cmdline/Makefile.*
.if ${TERMCAP_TYPE} == none
SUBST_SED.termcap+=	-e 's|ncurses||'
.else
SUBST_SED.termcap+=	-e 's|ncurses|${BUILDLINK_LIBNAME.termcap}|'
.endif

.include "../../devel/gmp/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
