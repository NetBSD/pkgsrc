# $NetBSD: Makefile,v 1.7 2002/07/03 14:22:41 abs Exp $
#

DISTNAME=	Mail-SpamAssassin-2.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5msa
CATEGORIES=	mail
#MASTER_SITES=	http://spamassassin.taint.org/released/
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.spamassassin.org/
COMMENT=	mail filter to identify spam

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../devel/p5-Time-HiRes

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/SpamAssassin/.packlist

post-patch:
	@(cd ${WRKSRC};							\
	for f in README Makefile.PL lib/Mail/SpamAssassin/Conf.pm ; do \
		${SED} -e "s,/usr/share,${PREFIX}/share," \
		       -e "s,/etc/mail,${PKG_SYSCONFBASE},g" $$f > $$f.fixed && \
		${MV} $$f.fixed $$f;					\
	done)

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
.for d in spamassassin spamassassin/sql spamassassin/spamd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/$d
.endfor
.for f in README procmailrc.example sample-nonspam.txt sample-spam.txt \
    sql/README sql/spamassassin.sql spamd/README.spamd
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/spamassassin/$f
.endfor

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
