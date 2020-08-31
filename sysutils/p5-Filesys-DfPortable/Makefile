# $NetBSD: Makefile,v 1.15 2020/08/31 18:11:31 wiz Exp $
#

DISTNAME=		Filesys-DfPortable-0.85
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		sysutils devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Filesys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Filesys-DfPortable
COMMENT=		Perl extension for filesystem disk space information

PERL5_MODULE_TYPE=	MakeMaker

PERL5_PACKLIST=		auto/Filesys/DfPortable/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
