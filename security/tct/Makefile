# $NetBSD: Makefile,v 1.2 2002/01/03 12:45:06 agc Exp $
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
	cd ${WRKSRC}/bin &&							\
	for f in grave-robber mactime; do					\
		${BSD_INSTALL_SCRIPT} $$f ${LOCALBASE}/sbin;			\
	done;									\
	for f in icat ils lastcomm major_minor pcat timeout unrm; do		\
		${BSD_INSTALL_PROGRAM} $$f ${LOCALBASE}/sbin;			\
	done
	cd ${WRKSRC}/extras &&							\
	for f in bdf ils2mac realpath; do					\
		${BSD_INSTALL_SCRIPT} $$f ${LOCALBASE}/sbin;			\
	done
	${BSD_INSTALL_SCRIPT} ${WRKSRC}/lazarus/lazarus ${LOCALBASE}/sbin
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/tct
	cd ${WRKSRC}/docs &&							\
	for f in README design-notes grave-robber.README lazarus.README mac.README; do \
		${BSD_INSTALL_DATA} $$f ${LOCALBASE}/share/doc/tct;		\
	done

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
