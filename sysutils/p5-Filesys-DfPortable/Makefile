# $NetBSD: Makefile,v 1.1.1.1 2009/03/22 21:34:26 sno Exp $
#

DISTNAME=		Filesys-DfPortable-0.85
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		sysutils devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Filesys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Filesys-DfPortable/
COMMENT=		Perl extension for filesystem disk space information

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	MakeMaker

PERL5_PACKLIST=		auto/Filesys/DfPortable/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
