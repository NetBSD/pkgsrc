# $NetBSD: Makefile,v 1.34 2018/08/22 09:46:30 wiz Exp $
#

DISTNAME=	tct-1.09
PKGREVISION=	10
CATEGORIES=	security
MASTER_SITES=	http://www.porcupine.org/forensics/

MAINTAINER=	frazee.23@osu.edu
HOMEPAGE=	http://www.porcupine.org/forensics/tct.html
COMMENT=	Programs to aid post-mortem after a break-in

MAKE_JOBS_SAFE=		no

DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip

USE_TOOLS+=	perl:run
REPLACE_PERL+=	bin/grave-robber bin/mactime bin/strip_tct_home
REPLACE_PERL+=	extras/bdf extras/ils2mac extras/realpath
REPLACE_PERL+=	lazarus/lazarus

MAKE_ENV+=	PERL5=${PERL5:Q}

INSTALLATION_DIRS+=	tct/bin tct/conf tct/etc share/doc/tct ${PERL5_INSTALLVENDORLIB}

do-install:
	cd ${WRKSRC}/bin &&						\
	for f in grave-robber mactime; do				\
		${INSTALL_SCRIPT} $$f ${DESTDIR}${PREFIX}/tct/bin;		\
	done;								\
	for f in file icat ils lastcomm major_minor md5 pcat timeout unrm; do \
		${INSTALL_PROGRAM} $$f ${DESTDIR}${PREFIX}/tct/bin;		\
	done
	cd ${WRKSRC}/extras &&						\
	for f in bdf ils2mac realpath; do				\
		${INSTALL_SCRIPT} $$f ${DESTDIR}${PREFIX}/tct/bin;		\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/lazarus/lazarus ${DESTDIR}${PREFIX}/tct/bin
	cd ${WRKSRC}/etc && ${INSTALL_DATA} magic ${DESTDIR}${PREFIX}/tct/etc
	cd ${WRKSRC}/docs &&						\
	for f in README design-notes grave-robber.README lazarus.README mac.README; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/doc/tct;		\
	done
	cd ${WRKSRC}/lib && ${INSTALL_DATA} *.pl ${DESTDIR}${PERL5_INSTALLVENDORLIB}
	cd ${WRKSRC}/conf && ${INSTALL_DATA} paths.pl *.cf ${DESTDIR}${PREFIX}/tct/conf

.include "../../mk/bsd.pkg.mk"
