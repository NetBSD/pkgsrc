# $NetBSD: Makefile,v 1.6 2002/09/08 23:30:38 wiz Exp $

DISTNAME=	Mail-SpamAssassin-2.31
PKGNAME=	spamassassin-2.31
SVR4_PKGNAME=	sa
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.spamassassin.org/
COMMENT=	mail filter to identify spam

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

CONFLICTS=	p5-Mail-SpamAssassin-[1-9]*

RCD_SCRIPTS=	spamd

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
	${SED}  -e 's:@PREFIX@:${PREFIX}:' ${FILESDIR}/spamd.sh \
	    > ${PREFIX}/etc/rc.d/spamd
.for d in spamassassin spamassassin/sql spamassassin/spamd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/$d
.endfor
.for f in README procmailrc.example sample-nonspam.txt sample-spam.txt \
    sql/README sql/spamassassin.sql spamd/README.spamd
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/spamassassin/$f
.endfor

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
