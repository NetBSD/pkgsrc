# $NetBSD: Makefile,v 1.12 2018/08/22 09:46:37 wiz Exp $
#

DISTNAME=		Filesys-Statvfs-0.82
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		sysutils devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Filesys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Filesys-Statvfs/
COMMENT=		Perl extension for statvfs() and fstatvfs()

PERL5_MODULE_TYPE=	MakeMaker

PERL5_PACKLIST=		auto/Filesys/Statvfs/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
