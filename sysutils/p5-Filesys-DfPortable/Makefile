# $NetBSD: Makefile,v 1.10 2016/06/08 19:24:25 wiz Exp $
#

DISTNAME=		Filesys-DfPortable-0.85
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		sysutils devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Filesys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Filesys-DfPortable/
COMMENT=		Perl extension for filesystem disk space information

PERL5_MODULE_TYPE=	MakeMaker

PERL5_PACKLIST=		auto/Filesys/DfPortable/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
