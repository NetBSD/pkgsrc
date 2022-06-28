# $NetBSD: Makefile,v 1.25 2022/06/28 11:36:02 wiz Exp $
#

DISTNAME=	Sys-Filesystem-1.406
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	sysutils devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sys-Filesystem
COMMENT=	Retrieve list of filesystems and their properties
LICENSE=	apache-2.0

DEPENDS+=	p5-Module-Pluggable>=4.8:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Params-Util>=1.00:../../devel/p5-Params-Util

PERL5_PACKLIST=		auto/Sys/Filesystem/.packlist

#pre-configure:
#	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

CONFIGURE_ENV+=		PATH_FSTAB=${WRKDIR}/fstab.phony

pre-configure:
	${TOUCH} ${WRKDIR}/fstab.phony

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
