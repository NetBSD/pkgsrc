# $NetBSD: Makefile,v 1.1 2024/01/10 16:48:23 schmonz Exp $

DISTNAME=		Mail-Qmail-Filter-1.32
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FA/FANY/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/dist/Mail-Qmail-Filter
COMMENT=		Modules for filtering between qmail-smtpd and qmail-queue
LICENSE=		artistic-2.0

DEPENDS+=		p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=		p5-Email-Valid-[0-9]*:../../mail/p5-Email-Valid
DEPENDS+=		p5-File-Scan-ClamAV-[0-9]*:../../security/p5-File-Scan-ClamAV
DEPENDS+=		p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=		p5-Mail-DKIM-[0-9]*:../../mail/p5-Mail-DKIM
DEPENDS+=		p5-Mail-DMARC-[0-9]*:../../mail/p5-Mail-DMARC
DEPENDS+=		p5-Mail-Qmail-Queue-[0-9]*:../../mail/p5-Mail-Qmail-Queue
DEPENDS+=		p5-Mail-SPF-[0-9]*:../../mail/p5-Mail-SPF
DEPENDS+=		spamassassin-[0-9]*:../../mail/spamassassin
DEPENDS+=		p5-Mo-[0-9]*:../../devel/p5-Mo
DEPENDS+=		p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
DEPENDS+=		p5-Qmail-Deliverable-[0-9]*:../../mail/p5-Qmail-Deliverable
DEPENDS+=		p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

USE_LANGUAGES=		# none
PERL5_PACKLIST=		auto/Mail/Qmail/Filter/.packlist

SUBST_CLASSES+=		varqmail
SUBST_STAGE.varqmail=	pre-configure
SUBST_FILES.varqmail=	lib/Mail/Qmail/Filter.pm
SUBST_VARS.varqmail=	QMAILDIR

BUILD_DEFS+=		QMAILDIR

pre-configure:
	${FIND} ${WRKSRC} -type f -name '*.orig' | ${XARGS} ${RM} -f

post-extract:
	cd ${WRKDIR} && ${MV} -f ${DISTNAME:C/[0-9]$/1/} ${DISTNAME}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
