# $NetBSD: Makefile,v 1.3 2002/07/05 07:04:29 tron Exp $

DISTNAME=	razor-agents-1.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ra
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=razor/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://razor.sourceforge.net/
COMMENT=	collaborative spam filtering network

DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net
DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/razor-agents/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
