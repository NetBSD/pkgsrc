# $NetBSD: Makefile,v 1.31 2014/02/20 11:38:14 jperkin Exp $

DISTNAME=	crack5.0
PKGNAME=	crack-5.0
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://dl.packetstormsecurity.net/Crackers/crack/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.crypticide.com/dropsafe/info/home.html
COMMENT=	The "Sensible" Unix Password Cracker

WRKSRC=		${WRKDIR}/c50a

INSTALLATION_DIRS=	sbin

REPLACE_INTERPRETER+=	xdawg
REPLACE.xdawg.old=	.*xdawg
REPLACE.xdawg.new=	${PREFIX}/libexec/crack/xdawg
REPLACE_FILES.xdawg=	dict/*/*

CHECK_INTERPRETER_SKIP+=	share/crack/extra/Dictstats.pl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
MAKE_ENV+=	LIBS="-lcrypt"
.endif

pre-configure:
	@if [ -f /usr/lib/libcrypt.a ]; then				\
		${ECHO} "XLIB+= -lcrypt" >> ${WRKSRC}/src/util/Makefile; \
	fi

pre-build:
	@(if [ ! -f /usr/share/dict/words ];then \
		${ECHO_MSG} "You may want to install the dict distribution into /usr/share/dict" ; \
		${ECHO_MSG} "to increase the size of the cracking dictionary." ; \
	fi)
	@${SED} 's|@@PREFIX@@|${PREFIX}|g;s|@@SH@@|${SH}|g' < ${WRKSRC}/Crack > ${WRKSRC}/Crack.new
	@${RM} -f ${WRKSRC}/Crack && ${MV} ${WRKSRC}/Crack.new ${WRKSRC}/Crack
	@${CHMOD} a+rx ${WRKSRC}/Crack

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Crack -makeonly

do-install:
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/libexec/crack
	@${CHMOD} go-rwx ${DESTDIR}${PREFIX}/libexec/crack
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/crack/conf
	@${CHMOD} go-rwx ${DESTDIR}${PREFIX}/share/crack
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/crack/dict
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/crack
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/crack/extra
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/crack/run
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/crack/scripts
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/crack/dict/1
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/crack/dict/2
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/crack/dict/3
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/crack/run
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/crack/run/dict
	${INSTALL_SCRIPT} ${WRKSRC}/Crack ${DESTDIR}${PREFIX}/sbin
	@${SED} 's|@@PREFIX@@|${PREFIX}|g' < ${WRKSRC}/Reporter > \
	    ${DESTDIR}${PREFIX}/sbin/Reporter
	@${CHMOD} 700 ${DESTDIR}${PREFIX}/sbin/Crack ${DESTDIR}${PREFIX}/sbin/Reporter
	${INSTALL_DATA} ${WRKSRC}/LICENCE ${DESTDIR}${PREFIX}/share/doc/crack/
	${INSTALL_DATA} ${WRKSRC}/manual.html ${DESTDIR}${PREFIX}/share/doc/crack/
	${INSTALL_DATA} ${WRKSRC}/manual.txt ${DESTDIR}${PREFIX}/share/doc/crack/
	@for i in \
		conf/dictrun.conf \
		conf/rules.weird \
		conf/rules.suffix \
		conf/rules.prefix \
		conf/rules.perm1u \
		conf/globrule.conf \
		conf/dictgrps.conf \
		conf/rules.basic \
		conf/network.conf \
		conf/rules.fast \
		conf/rules.perm2 \
		conf/rules.perm3 \
		conf/rules.perm4 \
		conf/rules.perm5 \
		conf/rules.perm6 \
		conf/rules.perm7 \
		conf/rules.perm1 \
		conf/rules.perm2u \
		conf/rules.prefixu \
		conf/rules.suffixu \
		conf/rules.perm3u \
		conf/rules.perm4u \
		conf/rules.perm5u \
		conf/rules.perm6u \
		conf/rules.perm7u \
		dict/1/assurnames.dwg \
		dict/1/asteroids.dwg \
		dict/1/biology.dwg \
		dict/1/cartoon.dwg \
		dict/1/chars.dwg \
		dict/1/common-passwords.txt.dwg \
		dict/1/crl.words.dwg \
		dict/1/dosref.dwg \
		dict/1/family-names.dwg \
		dict/1/famous.dwg \
		dict/1/female-names.dwg \
		dict/1/given-names.dwg \
		dict/1/jargon.dwg \
		dict/1/junk.dwg \
		dict/1/lcarrol.dwg \
		dict/1/list.dwg \
		dict/1/movies.dwg \
		dict/1/numbers.dwg \
		dict/1/myths-legends.dwg \
		dict/1/names.french.dwg \
		dict/1/other-names.dwg \
		dict/1/oz.dwg \
		dict/1/places.dwg \
		dict/1/python.dwg \
		dict/1/roget.words.dwg \
		dict/1/sf.dwg \
		dict/1/sports.dwg \
		dict/1/trek.dwg \
		dict/1/unix.dict.dwg \
		dict/1/yiddish.dwg \
		dict/1/abbr.dwg \
		dict/1/phrases.dwg \
		dict/1/fast-names.dwg \
		dict/1/male-names.dwg \
		dict/1/paradise.lost.dwg \
		dict/1/bad_pws.dat.dwg \
		dict/2/congress.dwg \
		dict/2/dico.dwg \
		dict/2/domains.dwg \
		dict/2/etc-hosts.dwg \
		dict/2/ethnologue.dwg \
		dict/2/kjbible.dwg \
		dict/2/shakespeare.dwg \
		dict/2/world.factbook.dwg \
		dict/2/zipcodes.dwg \
		dict/2/antworth.dwg \
		dict/2/colleges.dwg \
		dict/2/unabr.dict.dwg \
		dict/2/cis.dwg \
		dict/3/danish.words.dwg \
		dict/3/germanl.dwg \
		dict/3/koran.dwg \
		dict/3/words.dutch.dwg \
		dict/3/words.german.dwg \
		dict/3/words.japanese.dwg \
		dict/3/words.norwegian.dwg \
		dict/3/words.spanish.dwg \
		dict/3/words.swedish.dwg \
		dict/3/words.italian.dwg \
		dict/3/surnames.finnish.dwg \
		dict/3/chinese.dwg \
		extra/Makefile \
		extra/brute.c ;\
	do \
		${ECHO} ${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/share/crack/$$i ;\
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/share/crack/$$i ;\
	done
	@for i in \
		credits,v5.0.txt \
		faq.txt \
		fips181.txt \
		dicts,v5.0.txt \
		appendix,v4.1.txt \
		usenet-article.txt \
		threading.txt \
		gui.txt \
		humour.txt; \
	do \
		${ECHO} ${INSTALL_DATA} ${WRKSRC}/doc/$$i \
		    ${DESTDIR}${PREFIX}/share/doc/crack/$$i ;\
		${INSTALL_DATA} ${WRKSRC}/doc/$$i \
		    ${DESTDIR}${PREFIX}/share/doc/crack/$$i ;\
	done
	@for i in \
		scripts/smartcat \
		scripts/trad2spf \
		scripts/dictcomp \
		scripts/pauser \
		scripts/mkgecosd \
		scripts/shadmrg.sv \
		scripts/smartcomp \
		scripts/crack-sort \
		scripts/dodictgrp \
		scripts/nastygram \
		scripts/fbfilt   \
		scripts/fbmerge  \
		scripts/mkdictgrps \
		scripts/plaster \
		scripts/binstamp \
		scripts/dicttidy \
		scripts/mkcracker \
		scripts/netcrack \
		scripts/crack-rsh \
		scripts/crack-rcp \
		scripts/bsd2spf \
		scripts/tradmail2spf \
		scripts/bsdmail2spf \
		extra/Crack6 \
		extra/Crack7 \
		extra/b64encode \
		extra/b64decode \
		extra/Dictstats.pl; \
	do \
		${ECHO} ${INSTALL_SCRIPT} ${WRKSRC}/$$i \
		    ${DESTDIR}${PREFIX}/share/crack/$$i ;\
		${INSTALL_SCRIPT} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/share/crack/$$i ;\
	done
	@for i in \
		dawg \
		xdawg \
		cracker \
		dictfilt \
		kickdict; \
	do \
		${ECHO} ${INSTALL_PROGRAM} ${WRKSRC}/run/bin/$$i \
		    ${DESTDIR}${PREFIX}/libexec/crack/$$i ;\
		${INSTALL_PROGRAM} ${WRKSRC}/run/bin/$$i \
		    ${DESTDIR}${PREFIX}/libexec/crack/$$i ;\
	done

post-install:
	${SED} -e 's|PREFIX=${PREFIX}|PREFIX=${DESTDIR}${PREFIX}|' \
	    <${DESTDIR}${PREFIX}/sbin/Crack \
	    >${WRKDIR}/Crack.tmp
	${SH} ${WRKDIR}/Crack.tmp -makedict

.include "../../mk/bsd.pkg.mk"
