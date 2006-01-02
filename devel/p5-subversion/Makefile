# $NetBSD: Makefile,v 1.27 2006/01/02 21:13:45 epg Exp $

PKGNAME=	p5-subversion-${SVNVER}
COMMENT=	Perl bindings for Subversion

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../devel/subversion/Makefile.common"

SHLIBTOOL_OVERRIDE=	libtool

PERL5_CONFIGURE=	no
PERL5_OPTIONS+=		threads
PERL5_PACKLIST=		auto/SVN/_Core/.packlist

BUILD_TARGET=		swig-pl-lib swig-pl
INSTALL_TARGET=		install-swig-pl
TEST_TARGET=		check-swig-pl

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

.include "../../devel/subversion/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
