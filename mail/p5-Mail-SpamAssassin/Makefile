# $NetBSD: Makefile,v 1.1.1.1 2002/01/31 10:57:52 simonb Exp $
#

DISTNAME=	Mail-SpamAssassin-2.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5msa
CATEGORIES=	mail
#MASTER_SITES=	http://spamassassin.taint.org/released/
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://spamassassin.taint.org/
COMMENT=	mail filter to identify spam

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/SpamAssassin/.packlist

post-patch:
	@(cd ${WRKSRC};							\
	for f in lib/Mail/SpamAssassin/Conf.pm lib/Mail/SpamAssassin.pm ; do \
		${SED} -e "s,/usr/share,${PREFIX}/share," $$f > $$f.fixed && \
		${MV} $$f.fixed $$f;					\
	done)

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
.for d in spamassassin spamassassin/sql spamassassin/spamd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/$d
.endfor
.for f in README procmailrc.example sample-nonspam.txt sample-spam.txt \
    sql/README sql/spamassassin.sql spamd/README
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/spamassassin/$f
.endfor

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
