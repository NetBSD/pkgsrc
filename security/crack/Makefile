# $NetBSD: Makefile,v 1.2 1999/09/29 15:14:29 bouyer Exp $
# FreeBSD Id: ports/security/crack/Makefile,v 1.11 1999/09/04 19:24:50 obrien Exp

DISTNAME=	crack5.0
PKGNAME=	crack-5.0
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.win.tue.nl/pub/security/  \
		ftp://ftp.ox.ac.uk/pub/comp/security/software/crackers/  \
		ftp://ftp.auscert.org.au/pub/coast/mirrors/cert.org/tools/crack/ \
		ftp://ftp.riken.go.jp/pub/net/cert_security_tools/crack/

MAINTAINER=	bouyer@netbsd.org

RESTRICTED=	"Crypto; export-controlled"
WRKSRC=		${WRKDIR}/c50a

pre-configure:
	@${ECHO} "XLIB+= -lcrypt" >> ${WRKSRC}/src/util/Makefile

pre-build:
	@(if [ ! -f /usr/share/dict/words ];then \
		${ECHO_MSG} "You may want to install the dict distribution into /usr/share/dict" ; \
		${ECHO_MSG} "to increase the size of the cracking dictionary." ; \
	fi)

do-build:
	(cd ${WRKSRC} ; ./Crack -makeonly)
	(cd ${WRKSRC} ; ./Crack -makedict)

do-install:
	@${MKDIR} ${PREFIX}/crack
	@${MKDIR} ${PREFIX}/crack/conf ${PREFIX}/crack/dict ${PREFIX}/crack/doc
	@${MKDIR} ${PREFIX}/crack/extra ${PREFIX}/crack/run
	@${MKDIR} ${PREFIX}/crack/scripts
	@${MKDIR} ${PREFIX}/crack/dict/1 ${PREFIX}/crack/dict/2 \
		${PREFIX}/crack/dict/3
	@${MKDIR} ${PREFIX}/crack/run/bin
	@${MKDIR} ${PREFIX}/crack/run/bin/netbsd-1-i386_
	@${MKDIR} ${PREFIX}/crack/run/dict
	${INSTALL_SCRIPT} ${WRKSRC}/Crack ${PREFIX}/crack/
	${INSTALL_SCRIPT} ${WRKSRC}/Reporter ${PREFIX}/crack/
	${INSTALL_DATA} ${WRKSRC}/LICENCE ${PREFIX}/crack/
	${INSTALL_DATA} ${WRKSRC}/manual.html ${PREFIX}/crack/
	${INSTALL_DATA} ${WRKSRC}/manual.txt ${PREFIX}/crack/
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
		doc/credits,v5.0.txt \
		doc/faq.txt \
		doc/fips181.txt \
		doc/dicts,v5.0.txt \
		doc/appendix,v4.1.txt \
		doc/usenet-article.txt \
		doc/threading.txt \
		doc/gui.txt \
		doc/humour.txt \
		run/dict/2.dwg.gz \
		run/dict/1.dwg.gz \
		run/dict/3.dwg.gz \
		extra/Makefile \
		extra/brute.c ;\
	do \
		echo ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/crack/$$i ;\
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/crack/$$i ;\
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
		echo ${INSTALL_SCRIPT} ${WRKSRC}/$$i ${PREFIX}/crack/$$i ;\
		${INSTALL_SCRIPT} ${WRKSRC}/$$i ${PREFIX}/crack/$$i ;\
	done
	@for i in \
		run/bin/netbsd-1-i386_/dawg \
		run/bin/netbsd-1-i386_/xdawg \
		run/bin/netbsd-1-i386_/cracker \
		run/bin/netbsd-1-i386_/dictfilt \
		run/bin/netbsd-1-i386_/kickdict; \
	do \
		echo ${INSTALL_PROGRAM} ${WRKSRC}/$$i ${PREFIX}/crack/$$i ;\
		${INSTALL_PROGRAM} ${WRKSRC}/$$i ${PREFIX}/crack/$$i ;\
	done

.include "../../mk/bsd.pkg.mk"
