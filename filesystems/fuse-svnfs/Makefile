# $NetBSD: Makefile,v 1.47 2020/04/12 08:28:37 adam Exp $
#

DISTNAME=	svnfs-0.4
PKGREVISION=	41
CATEGORIES=	filesystems
MASTER_SITES=	http://www.jmadden.eu/wp-content/uploads/svnfs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jmadden.eu/
COMMENT=	FUSE filesystem for accessing SVN repositories
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl

LDFLAGS.DragonFly+=	-lsvn_subr-1

REPLACE_PERL=	svn-config.pl

SUBST_CLASSES+=		svn
SUBST_FILES.svn=	svn-config.pl
SUBST_MESSAGE.svn=	Fixing subversion pathnames in ${SUBST_FILES.svn}
SUBST_STAGE.svn=	pre-configure
SUBST_VARS.svn=		LOCALBASE

BUILDLINK_ABI_DEPENDS.subversion-base+=	subversion-base>=1.4.3nb2

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
