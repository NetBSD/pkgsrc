# $NetBSD: Makefile,v 1.38 2002/09/15 19:16:44 kim Exp $
#

DISTNAME=	tcsh-6.12.00
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.astron.com/pub/tcsh/ \
		ftp://ftp.gw.com/pub/unix/tcsh/ \
		ftp://ftp.funet.fi/pub/unix/shells/tcsh/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.tcsh.org/
COMMENT=	Extended C-shell with many useful features

GNU_CONFIGURE=	yes
ALL_TARGET=	all catalogs
INSTALL_TARGET=	install install.man

NLSDIR=		share/nls
PLIST_SRC=	${WRKDIR}/PLIST-src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
OS_VERSION!=	${ECHO} ${OS_VERSION} | ${SED} -e 's|5\.|2.|'
LOWER_OPSYS=	solaris${OS_VERSION}
.endif

post-install:
	@${ECHO} "Installing message catalogues"
	@[ -d ${PREFIX}/${NLSDIR}/C ] || \
	    ${INSTALL_DATA_DIR} ${PREFIX}/${NLSDIR}/C
	@${INSTALL_DATA} ${WRKSRC}/tcsh.C.cat ${PREFIX}/${NLSDIR}/C/tcsh.cat
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@${ECHO} ${NLSDIR}/C/tcsh.cat >> ${PLIST_SRC}
	@for i in 						\
	    et:ISO_8859-15:et:EE				\
	    finnish:ISO_8859-1:fi:FI				\
	    french:ISO_8859-1:fr:BE:CA:CH:FR			\
	    german:ISO_8859-1:de:AT:CH:DE			\
	    greek:ISO_8859-7:el:GR				\
	    italian:ISO_8859-1:it:CH:IT				\
	    ja:eucJP:ja:JP					\
	    pl:ISO_8859-2:pl:PL					\
	    russian:KOI8-R:ru:RU:SU				\
	    spanish:ISO_8859-1:es:ES				\
	    ukrainian:KOI8-U:uk:UA				\
	    ;							\
	do							\
	    OIFS="${IFS}";					\
	    IFS=":${IFS}";					\
	    set -- $$i;						\
	    IFS="${OIFS}";					\
	    l=$$1; shift;					\
	    s=$$1; shift;					\
	    c=$$1; shift;					\
	    o=;							\
	    while [ $$# -gt 0 ]; do				\
		d=${NLSDIR}/$${c}_$$1.$${s};			\
		[ -d ${PREFIX}/$$d ] ||				\
		    ${INSTALL_DATA_DIR} ${PREFIX}/$$d;		\
		if [ -z "$$o" ]; then				\
		    o="$$d";					\
		    ${INSTALL_DATA} ${WRKSRC}/tcsh.$${l}.cat	\
			${PREFIX}/$${d}/tcsh.cat;		\
		else						\
		    ${LN} -f ${PREFIX}/$${o}/tcsh.cat		\
			${PREFIX}/$${d};			\
		fi;						\
		${ECHO} $${d}/tcsh.cat >> ${PLIST_SRC};		\
		shift 1;					\
	    done;						\
	done
	@${ECHO} "updating /etc/shells";			\
	${TOUCH} /etc/shells;					\
	${CP} /etc/shells /etc/shells.bak;			\
	if [ "${PREFIX}" = / ];then				\
		TCSHPATH=/bin/tcsh;				\
	else							\
		TCSHPATH=${PREFIX}/bin/tcsh;			\
	fi;							\
	(							\
		${GREP} -v '^$${TCSHPATH}$$' /etc/shells.bak || \
		${TRUE};					\
		${ECHO} $${TCSHPATH}				\
	) >/etc/shells

.include "../../mk/bsd.pkg.mk"
