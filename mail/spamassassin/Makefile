# $NetBSD: Makefile,v 1.12 2002/10/21 07:57:07 jlam Exp $

DISTNAME=	Mail-SpamAssassin-2.43
PKGNAME=	spamassassin-2.43
PKGREVISION=	0
SVR4_PKGNAME=	sa
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}			\
		http://www.spamassassin.org/released/

MAINTAINER=	heinz-sa@netbsd.org
HOMEPAGE=	http://www.spamassassin.org/
COMMENT=	mail filter to identify spam

DEPENDS+=	procmail>=3.22:../../mail/procmail
DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	p5-HTML-Parser>=3.0:../../www/p5-HTML-Parser
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64

BUILDLINK_DEPENDS.perl=	perl>=5.6.0
USE_BUILDLINK2=		YES

CONFLICTS=		p5-Mail-SpamAssassin-[1-9]*

GNU_CONFIGURE=		YES
PKG_SYSCONFSUBDIR=	spamassassin

PERL5_CONFIGURE=	NO
MAKE_PARAMS=		SYSCONFDIR="${PKG_SYSCONFDIR}"
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/SpamAssassin/.packlist

RCD_SCRIPTS=		spamd
RCD_SCRIPT_SRC.spamd=	${WRKDIR}/${DISTNAME}/spamd/netbsd-rc-script.sh

EGDIR=			${PREFIX}/share/examples/spamassassin
DOCDIR=			${PREFIX}/share/doc/spamassassin
RULESDIR=		${PREFIX}/share/spamassassin

CONF_FILES+=		${EGDIR}/local.cf  ${PKG_SYSCONFDIR}/local.cf
CONF_FILES+=		${PREFIX}/share/spamassassin/user_prefs.template\
			  ${PKG_SYSCONFDIR}/user_prefs.template
SUPPORT_FILES_PERMS+=	${EGDIR}/netbsd_lists.cf			\
			  ${PKG_SYSCONFDIR}/netbsd_lists.cf ${SHAREOWN}	\
			  ${SHAREGRP} ${SHAREMODE}

.include "../../mk/bsd.prefs.mk"
# the 'spamd' RCD_SCRIPT behaves differently if we run NetBSD 1.6 or later
.if ${OS_VERSION:M1.[0-5]*}
INTERPRETER_SUPPORT=NO
.else
INTERPRETER_SUPPORT=YES
.endif
FILES_SUBST+=		INTERPRETER_SUPPORT=${INTERPRETER_SUPPORT}

test:	build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} test

pre-configure: perl5-configure

post-configure:
.for f in INSTALL README lib/Mail/SpamAssassin/Conf.pm			\
	  spamd/README.spamd-vpopmail sql/README
	@${SED} -e "s,/usr/share,${PREFIX}/share,g"			\
		-e "s,/usr/bin,${PREFIX}/bin,g"				\
		-e "s,/usr/lib,${PREFIX}/lib,g"				\
		-e "s,/etc/mail,${PKG_SYSCONFBASE},g"			\
		${WRKSRC}/${f} > ${WRKSRC}/${f}.fixed &&		\
	  ${MV} ${WRKSRC}/${f}.fixed ${WRKSRC}/${f}
.endfor

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
.for d in masses/lib/Mail spamd sql tools
	${INSTALL_DATA_DIR}  ${DOCDIR}/$d
.endfor
	${INSTALL_DATA_DIR}  ${PREFIX}/share/doc/html/spamassassin
	${INSTALL_DATA} ${WRKSRC}/ninjabutton.png                       \
	  ${PREFIX}/share/doc/html/spamassassin/
.for f in INSTALL License README TRADEMARK sample-nonspam.txt		\
	  sample-spam.txt sql/README sql/spamassassin.sql		\
	  spamd/README.spamd spamd/README.spamd-vpopmail
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}/$f
.endfor
	${INSTALL_DATA} ${WRKSRC}/rules/STATISTICS.txt ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/masses/lib/Mail/ArchiveIterator.pm	\
	  ${DOCDIR}/masses/lib/Mail/ArchiveIterator.pm
	@(cd ${WRKSRC}/masses/;						\
	  for f in *; do						\
	    if ${TEST} -f $$f; then					\
	      if ${TEST} -x $$f ; then					\
		${SED} -e "1s,/usr/bin/perl,${PERL5}," < $$f		\
		  > $${f}.fixed && ${MV} $${f}.fixed $$f &&		\
		  ${CHMOD} +x $$f &&					\
		  ${INSTALL_SCRIPT} $$f ${DOCDIR}/masses/$$f;		\
	      else							\
		${INSTALL_DATA} $$f ${DOCDIR}/masses/$$f;		\
	      fi;							\
	    fi;								\
	  done)
	${INSTALL_DATA} ${WRKSRC}/procmailrc.example ${EGDIR}/procmailrc.example
	${INSTALL_DATA} ${WRKSRC}/rules/local.cf ${EGDIR}/local.cf
	${INSTALL_DATA} ${FILESDIR}/netbsd_lists.cf ${EGDIR}/
.for f in check_whitelist speedtest translation_prep.pl
	@(cd ${WRKSRC}/tools/;						\
	  ${SED} -e "1s,/usr/bin/perl,${PERL5},"			\
		 -e "1s,/usr/local/bin/perl,${PERL5}," < $f		\
	    > ${f}.fixed && ${MV} ${f}.fixed $f;			\
	  ${INSTALL_SCRIPT} $f ${DOCDIR}/tools/$f )
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/README.speedtest		\
	  ${DOCDIR}/tools/README.speedtest

post-install:
	${CHOWN} ${SHAREOWN} ${RULESDIR}/*
	${CHGRP} ${SHAREGRP} ${RULESDIR}/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
