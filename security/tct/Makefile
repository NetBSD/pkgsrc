# $NetBSD: Makefile,v 1.5 2002/01/05 16:20:54 agc Exp $
#

DISTNAME=	tct-1.09
CATEGORIES=	security
MASTER_SITES=	http://www.porcupine.org/forensics/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.porcupine.org/forensics/tct.html
COMMENT=	programs to aid post-mortem after a break-in

REPLACE_PERL=	bin/grave-robber bin/mactime bin/strip_tct_home
REPLACE_PERL+=	extras/bdf extras/ils2mac extras/realpath
REPLACE_PERL+=	lazarus/lazarus

do-install:
	${BSD_INSTALL_PROGRAM_DIR} ${LOCALBASE}/tct/bin
	cd ${WRKSRC}/bin &&							\
	for f in grave-robber mactime; do					\
		${BSD_INSTALL_SCRIPT} $$f ${LOCALBASE}/tct/bin;			\
	done;									\
	for f in file icat ils lastcomm major_minor md5 pcat timeout unrm; do	\
		${BSD_INSTALL_PROGRAM} $$f ${LOCALBASE}/tct/bin;		\
	done
	cd ${WRKSRC}/extras &&							\
	for f in bdf ils2mac realpath; do					\
		${BSD_INSTALL_SCRIPT} $$f ${LOCALBASE}/tct/bin;			\
	done
	${BSD_INSTALL_SCRIPT} ${WRKSRC}/lazarus/lazarus ${LOCALBASE}/tct/bin
	${BSD_INSTALL_PROGRAM_DIR} ${LOCALBASE}/tct/etc
	cd ${WRKSRC}/etc && ${BSD_INSTALL_DATA} magic ${LOCALBASE}/tct/etc
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/tct
	cd ${WRKSRC}/docs &&							\
	for f in README design-notes grave-robber.README lazarus.README mac.README; do \
		${BSD_INSTALL_DATA} $$f ${LOCALBASE}/share/doc/tct;		\
	done
	${INSTALL_DATA_DIR} ${PERL5_SITEARCH}
	cd ${WRKSRC}/lib && ${BSD_INSTALL_DATA} *.pl ${PERL5_SITEARCH}
	${BSD_INSTALL_PROGRAM_DIR} ${LOCALBASE}/tct/conf
	cd ${WRKSRC}/conf && ${BSD_INSTALL_DATA} paths.pl *.cf ${LOCALBASE}/tct/conf

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
