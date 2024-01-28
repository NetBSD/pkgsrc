# $NetBSD: Makefile,v 1.4 2024/01/28 21:10:34 schmonz Exp $

DISTNAME=		Qmail-Deliverable-1.09
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSIMERSON/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Qmail::Deliverable
COMMENT=		Deliverability check daemon for qmail
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# none
PERL5_PACKLIST=		auto/Qmail/Deliverable/.packlist

SUBST_CLASSES+=		varqmail
SUBST_STAGE.varqmail=	pre-configure
SUBST_FILES.varqmail=	qpsmtpd-plugin/qmail_deliverable
SUBST_FILES.varqmail+=	lib/Qmail/Deliverable.pm
SUBST_FILES.varqmail+=	lib/Qmail/Deliverable/Comparison.pod
SUBST_VARS.varqmail=	QMAILDIR

BUILD_DEFS+=		QMAILDIR

pre-configure:
	${FIND} ${WRKSRC} -type f -name '*.orig' | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
