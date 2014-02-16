# $NetBSD: Makefile,v 1.13 2014/02/16 11:57:22 sno Exp $
#

DISTNAME=	Sys-Filesystem-1.405
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sys-Filesystem/
COMMENT=	Retrieve list of filesystems and their properties
LICENSE=	apache-2.0

DEPENDS+=	p5-Module-Pluggable>=4.8:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Params-Util>=1.00:../../devel/p5-Params-Util

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Sys/Filesystem/.packlist

#pre-configure:
#	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

CONFIGURE_ENV+=		PATH_FSTAB=${WRKDIR}/fstab.phony

pre-configure:
	${TOUCH} ${WRKDIR}/fstab.phony

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
