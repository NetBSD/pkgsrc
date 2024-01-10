# $NetBSD: Makefile,v 1.1 2024/01/10 11:51:45 schmonz Exp $

DISTNAME=		Qmail-Deliverable-1.07
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JU/JUERD/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Qmail::Deliverable
COMMENT=		Deliverability check daemon for qmail
LICENSE=		public-domain

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
