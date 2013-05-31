# $NetBSD: Makefile,v 1.6 2013/05/31 12:42:02 wiz Exp $
#

DISTNAME=		Filesys-Df-0.92
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		sysutils devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Filesys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Filesys-Df/
COMMENT=		Perl extension for filesystem disk space information

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_MODULE_TYPE=	MakeMaker

PERL5_PACKLIST=		auto/Filesys/Df/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
