# $NetBSD: Makefile,v 1.4 2001/11/26 06:50:05 jlam Exp $

DISTNAME=		Mail-ListDetector-0.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mli
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module to detect whether a message is from a mailing list

DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Email-Valid-[0-9]*:../../mail/p5-Email-Valid
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/ListDetector/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
