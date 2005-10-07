# $NetBSD: Makefile,v 1.1.1.1 2005/10/07 23:02:54 wulf Exp $

DISTNAME=	gnuradio-examples-0.4
COMMENT=	GUI framework for GNU Radio based on wxPython
COMMENT=	Examples for GNU Radio

EXAMPLE_DIR=	${LOCALBASE}/share/examples/gnuradio/python

do-install:
	for file in audio gmsk mc4020 usrp;				\
	do								\
		${INSTALL_SCRIPT_DIR} ${EXAMPLE_DIR}/$${file};		\
		${INSTALL_SCRIPT} ${WRKSRC}/python/$${file}/*\.py	\
		  ${EXAMPLE_DIR}/$${file};				\
	done

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/gnuradio-wxgui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
