# $NetBSD: Makefile,v 1.7 2002/02/06 16:58:15 jlam Exp $
#

DISTNAME=	tct-1.09
CATEGORIES=	security
MASTER_SITES=	http://www.porcupine.org/forensics/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.porcupine.org/forensics/tct.html
COMMENT=	programs to aid post-mortem after a break-in

DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip

REPLACE_PERL=	bin/grave-robber bin/mactime bin/strip_tct_home
REPLACE_PERL+=	extras/bdf extras/ils2mac extras/realpath
REPLACE_PERL+=	lazarus/lazarus

do-install:
	${INSTALL_PROGRAM_DIR} ${LOCALBASE}/tct/bin
	cd ${WRKSRC}/bin &&							\
	for f in grave-robber mactime; do					\
		${INSTALL_SCRIPT} $$f ${LOCALBASE}/tct/bin;			\
	done;									\
	for f in file icat ils lastcomm major_minor md5 pcat timeout unrm; do	\
		${INSTALL_PROGRAM} $$f ${LOCALBASE}/tct/bin;		\
	done
	cd ${WRKSRC}/extras &&							\
	for f in bdf ils2mac realpath; do					\
		${INSTALL_SCRIPT} $$f ${LOCALBASE}/tct/bin;			\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/lazarus/lazarus ${LOCALBASE}/tct/bin
	${INSTALL_PROGRAM_DIR} ${LOCALBASE}/tct/etc
	cd ${WRKSRC}/etc && ${INSTALL_DATA} magic ${LOCALBASE}/tct/etc
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/tct
	cd ${WRKSRC}/docs &&							\
	for f in README design-notes grave-robber.README lazarus.README mac.README; do \
		${INSTALL_DATA} $$f ${LOCALBASE}/share/doc/tct;		\
	done
	${INSTALL_DATA_DIR} ${PERL5_SITEARCH}
	cd ${WRKSRC}/lib && ${INSTALL_DATA} *.pl ${PERL5_SITEARCH}
	${INSTALL_PROGRAM_DIR} ${LOCALBASE}/tct/conf
	cd ${WRKSRC}/conf && ${INSTALL_DATA} paths.pl *.cf ${LOCALBASE}/tct/conf

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
