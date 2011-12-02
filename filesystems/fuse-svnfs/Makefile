# $NetBSD: Makefile,v 1.11 2011/12/02 07:13:49 sbd Exp $
#

DISTNAME=	svnfs-0.4
PKGREVISION=	8
CATEGORIES=	filesystems
MASTER_SITES=	http://www.jmadden.eu/wp-content/uploads/svnfs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jmadden.eu/
COMMENT=	FUSE filesystem for accessing SVN repositories
LICENSE=	gnu-gpl-v2

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
