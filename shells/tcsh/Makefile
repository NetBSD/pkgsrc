# $NetBSD: Makefile,v 1.19 1999/08/17 16:11:27 agc Exp $
#

DISTNAME=	tcsh-6.09
PKGNAME=	tcsh-6.09.00
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.astron.com/pub/tcsh/ \
		ftp://ftp.gw.com/pub/unix/tcsh/ \
		ftp://ftp.funet.fi/pub/unix/shells/tcsh/

MAINTAINER=	kim@tac.nyc.ny.us

WRKSRC=		${WRKDIR}/${PKGNAME}

GNU_CONFIGURE=	yes
ALL_TARGET=	all catalogs
INSTALL_TARGET=	install install.man

NLSDIR=		share/nls
PLIST_SRC=	${WRKDIR}/PLIST-src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
OS_VERSION!=	echo ${OS_VERSION} | sed -e 's|5\.|2.|'
LOWER_OPSYS=	solaris${OS_VERSION}
.endif

post-install:
	@${ECHO} "Installing message catalogues"
	@${INSTALL_DATA} ${WRKSRC}/tcsh.C.cat ${PREFIX}/${NLSDIR}/C/tcsh.cat
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@${ECHO} ${NLSDIR}/C/tcsh.cat >> ${PLIST_SRC}
	@for i in 						\
	    french:ISO_8859-1:fr:BE:CA:CH:FR			\
	    german:ISO_8859-1:de:AT:CH:DE			\
	    greek:ISO_8859-7:el:GR				\
	    italian:ISO_8859-1:it:CH:IT				\
	    ja:EUC:ja:JP					\
	    spanish:ISO_8859-1:es:ES				\
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
	${CP} /etc/shells /etc/shells.bak;			\
	(							\
		${GREP} -v ${PREFIX}/bin/tcsh /etc/shells.bak;	\
		${ECHO} ${PREFIX}/bin/tcsh			\
	) >/etc/shells

.include "../../mk/bsd.pkg.mk"
