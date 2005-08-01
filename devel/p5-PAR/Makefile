# $NetBSD: Makefile,v 1.1.1.1 2005/08/01 17:58:38 rillig Exp $
#

DISTNAME=		PAR-0.89
CATEGORIES=		devel
MASTER_SITES=		http://search.cpan.org/CPAN/authors/id/A/AU/AUTRIJUS/

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://search.cpan.org/CPAN/authors/id/A/AU/AUTRIJUS/
COMMENT=		Cross-Platform Packaging and Debugging Tool

PERL5_DEPENDS+=		archivers,p5-Archive-Zip,1
PERL5_DEPENDS+=		devel,p5-Module-ScanDeps,0.45
PERL5_DEPENDS+=		devel,p5-PAR-Dist,0.06
PERL5_DEPENDS+=		security,p5-Module-Signature,0.35

PERL5_PACKLIST=		auto/PAR/.packlist

.for dep in ${PERL5_DEPENDS}
.for cat in ${dep:C/^(.*),(.*),(.*)$/\1/}
.for pkg in ${dep:C/^(.*),(.*),(.*)$/\2/}
.for ver in ${dep:C/^(.*),(.*),(.*)$/\3/}
DEPENDS+=		${pkg}>=${ver}:../../${cat}/${pkg}
.endfor
.endfor
.endfor
.endfor

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
