# $NetBSD: Makefile,v 1.3 2004/04/05 20:53:20 heinz Exp $
#

DISTNAME=		Sys-Hostname-Long-1.0
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Sys-Hostname-Long/
COMMENT=		Try to get the full hostname in Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Sys/Hostname/Long/.packlist

pre-configure:
	@ ${TEST} -r ${WRKSRC}/lib/Sys/Hostname/Long.pm.orig && \
	  ${RM} ${WRKSRC}/lib/Sys/Hostname/Long.pm.orig ; :

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
