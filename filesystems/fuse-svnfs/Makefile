# $NetBSD: Makefile,v 1.1.1.1 2007/12/13 07:00:16 bjs Exp $
#

DISTNAME=	svnfs-0.4
CATEGORIES=	filesystems
MASTER_SITES=	http://www.jmadden.eu/wp-content/uploads/svnfs/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://www.jmadden.eu/
COMMENT=	FUSE filesystem for accessing SVN repositories
EXTRACT_SUFX=	.tgz

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl

REPLACE_PERL=	svn-config.pl

SUBST_CLASSES+=		svn
SUBST_FILES.svn=	svn-config.pl
SUBST_MESSAGE.svn=	Fixing subversion pathnames in ${SUBST_FILES.svn}
SUBST_STAGE.svn=	post-patch
SUBST_VARS.svn=		LOCALBASE

BUILDLINK_ABI_DEPENDS.subversion-base+=	subversion-base>=1.4.3nb2

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
