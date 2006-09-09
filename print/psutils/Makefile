# $NetBSD: Makefile,v 1.35 2006/09/09 02:46:08 obache Exp $

DISTNAME=	psutils-p17
PKGNAME=	psutils-1.17
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dcs.ed.ac.uk/pub/ajcd/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.go.dlr.de:8081/pdinfo_dv/psutils.html
COMMENT=	Utilities for manipulating PostScript documents

WRKSRC=		${WRKDIR}/psutils
USE_TOOLS+=	perl:run

.include "../../mk/bsd.prefs.mk"

PAPERSIZE?=	A4

MAKE_ENV+=	PERL5=${PERL5:Q}
MAKE_FLAGS+=	PAPER=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`
MAKE_FILE=	Makefile.unix

EGDIR=		${PREFIX}/share/examples/psutils
CONF_FILES=	${EGDIR}/psutils.cfg ${PKG_SYSCONFDIR}/psutils.cfg

post-patch:
	cd ${WRKSRC}; for file in psutil.c; do				\
		${MV} -f $$file $$file.in;				\
		${SED} -e "s|@prefix@|${PREFIX}|g" $$file.in > $$file;	\
	done

pre-configure:
	@case "X${PAPERSIZE}" in					\
	XA4|XLetter)							\
		;;							\
	XA3|XA5|XB5|Xledger|Xstatement|Xexecutive|Xfolio|Xquarto|X10x14)\
		${ECHO} "Other packages do not recognise ${PAPERSIZE}";	\
		;;							\
	*)								\
		${ECHO} "Error: PAPERSIZE invalid: \"${PAPERSIZE}\"";	\
		${ECHO} "Possible values are:";				\
		${ECHO} "   A3, A4 (default), A5, B5, Letter, Legal,";	\
		${ECHO} "   Ledger, Tabloid, Statement, Executive,";	\
		${ECHO} "   Folio, Quarto, and 10x14.";			\
		${FALSE};						\
		;;							\
	esac

post-install:
	for f in epsffit psbook psnup psresize psselect pstops; do	\
		strip ${PREFIX}/bin/$$f;				\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	low=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`;		\
	${ECHO} "PAPERSIZE=$$low" > ${EGDIR}/psutils.cfg;

.include "../../mk/bsd.pkg.mk"
