# $NetBSD: Makefile,v 1.39 2008/01/18 05:14:36 tnn Exp $

PKGNAME=	p5-subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	Perl bindings for Subversion

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

.include "../../devel/subversion/Makefile.common"

SHLIBTOOL_OVERRIDE=	# empty

USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
PERL5_OPTIONS+=		threads
PERL5_PACKLIST=		auto/SVN/_Core/.packlist

BUILD_TARGET=		swig-pl-lib swig-pl
INSTALL_TARGET=		install-swig-pl
TEST_TARGET=		check-swig-pl

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
