# $NetBSD: Makefile,v 1.60 2012/12/16 01:52:11 obache Exp $

PKGNAME=	p5-subversion-${SVNVER}
PKGREVISION=	8
COMMENT=	Perl bindings for Subversion

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_JOBS_SAFE=		no

.include "../../devel/subversion/Makefile.common"

SHLIBTOOL_OVERRIDE=	# empty

USE_TOOLS+=		perl
PERL5_CONFIGURE=	no
PERL5_OPTIONS+=		threads
PERL5_PACKLIST=		auto/SVN/_Core/.packlist

BUILD_TARGET=		swig-pl
INSTALL_TARGET=		install-swig-pl
TEST_TARGET=		check-swig-pl
MAKE_ENV+=		SUBVERSION_BASE_PREFIX=${BUILDLINK_PREFIX.subversion-base}

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
