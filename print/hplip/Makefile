# $NetBSD: Makefile,v 1.17 2013/03/16 22:45:45 dholland Exp $
#

DISTNAME=		hplip-3.12.11
PKGREVISION=		3
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=hplip/}

MAINTAINER=		schnoebe@NetBSD.org
HOMEPAGE=		http://hplipopensource.com/
COMMENT=		HP Linux Imaging and Printing
LICENSE=		gnu-gpl-v2 AND mit AND modified-bsd

CONFLICTS+=		hpijs-[0-9]*

FILES_SUBST+=           CUPS_USER=${CUPS_USER}
FILES_SUBST+=           CUPS_GROUP=${CUPS_GROUP}

PKG_GROUPS_VARS+=       CUPS_GROUP
PKG_USERS_VARS+=        CUPS_USER

BUILD_DEFS+=            CUPS_USER CUPS_GROUP VARBASE

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++ # fortran
USE_TOOLS+=		aclocal autoconf automake gmake pkg-config
USE_TOOLS+=		perl:run

CONFIGURE_ARGS=		--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=${VARBASE} \
			--with-cupsbackenddir=${PREFIX}/libexec/cups/backend \
			--with-cupsfilterdir=${PREFIX}/libexec/cups/filter \
			--with-hpppddir=${PREFIX}/share/hplip/ppd/HP
CONFIGURE_ARGS+=	--enable-network-build
CONFIGURE_ARGS+=	--disable-pp-build
CONFIGURE_ARGS+=	--enable-hpcups-install
CONFIGURE_ARGS+=	--enable-hpijs-install
CONFIGURE_ARGS+=	--enable-cups-drv-install
CONFIGURE_ARGS+=	--enable-cups-ppd-install
CONFIGURE_ARGS+=	--enable-foomatic-drv-install
CONFIGURE_ARGS+=	--enable-foomatic-ppd-install
CONFIGURE_ARGS+=	--enable-foomatic-rip-hplip-install

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
EGFILES=		hp/hplip.conf

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
INSTALL_MAKE_FLAGS+=	localstatedir=${EGDIR}
INSTALL_MAKE_FLAGS+=	systraydir=${EGDIR}/xdg/autostart
INSTALL_MAKE_FLAGS+=	mimedir=${EGDIR}/cups

OWN_DIRS+=		${PKG_SYSCONFDIR}/hp
OWN_DIRS+=		${VARBASE}/lib/hp
OWN_DIRS+=		${PREFIX}/share/examples/hplip/log/hp

OWN_DIRS_PERMS+=	${PREFIX}/share/examples/hplip/log/hp ${CUPS_USER} ${CUPS_GROUP} 0774

PLIST_SRC=		PLIST.base

.include "options.mk"

.for file in ${EGFILES}
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor
CONF_FILES+=

REPLACE_PYTHON=		*.py */*.py */*/*.py
REPLACE_PYTHON+=	fax/filters/pstotiff
REPLACE_PYTHON+=	prnt/filters/hpps
REPLACE_PERL=		prnt/filters/hpcac prnt/hpijs/foomatic-rip-hplip

PY_PATCHPLIST=		yes

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		post-configure
SUBST_MESSAGE.fix-python=	Fixing python invocations in Python files.
SUBST_FILES.fix-python=		check.py scan.py setup.py
SUBST_FILES.fix-python+=	base/utils.py base/pkit.py
SUBST_FILES.fix-python+=	installer/core_install.py
SUBST_FILES.fix-python+=	ui/nodevicesform.py ui/devmgr4.py
SUBST_FILES.fix-python+=	ui4/nodevicesdialog.py ui4/devmgr5.py
SUBST_SED.fix-python=	-e 's,\(['\''"]\)python ,\1${PYTHONBIN} ,g'

SUBST_CLASSES+=			fix-paths-0
SUBST_STAGE.fix-paths-0=	pre-configure
SUBST_MESSAGE.fix-paths-0=	Fixing /var/run in hplip.conf.in.
SUBST_FILES.fix-paths-0=	hplip.conf.in
SUBST_SED.fix-paths-0=	-e 's,run=/var/run,run=${VARBASE}/run,g'

SUBST_CLASSES+=			fix-paths-1
SUBST_STAGE.fix-paths-1=	post-configure
SUBST_MESSAGE.fix-paths-1=	Fixing /etc and /var paths in Python and C++ files.
SUBST_FILES.fix-paths-1=	check.py base/codes.py base/g.py base/utils.py
SUBST_FILES.fix-paths-1+=	installer/core_install.py
SUBST_FILES.fix-paths-1+=	fax/backend/hpfax.py prnt/cups.py
SUBST_FILES.fix-paths-1+=	ui/devmgr4.py ui4/devmgr5.py
SUBST_FILES.fix-paths-1+=	prnt/hpcups/HPCupsFilter.cpp prnt/hpcups/Utils.cpp
SUBST_FILES.fix-paths-1+=	prnt/hpijs/globals.cpp prnt/hpijs/hpcupsfax.cpp
SUBST_FILES.fix-paths-1+=	prnt/hpijs/hpijs.cpp
SUBST_SED.fix-paths-1=	-e 's,\([ '\''"=]\)/etc/hp,\1${PKG_SYSCONFDIR}/hp,g'
SUBST_SED.fix-paths-1+=	-e 's,\([ '\''"=]\)/etc/cups,\1${PKG_SYSCONFDIR}/cups,g'
SUBST_SED.fix-paths-1+=	-e 's,\([ '\''"=]\)/etc/sane.d,\1${PKG_SYSCONFDIR}/sane.d,g'
SUBST_SED.fix-paths-1+=	-e 's,\([ '\''"=]\)/var/lib/hp,\1${VARBASE}/lib/hp,g'
SUBST_SED.fix-paths-1+=	-e 's,\([ '\''"=]\)/var/log/cups,\1${VARBASE}/log/cups,g'
SUBST_SED.fix-paths-1+=	-e 's,\([ '\''"=]\)/var/spool/cups,\1${VARBASE}/spool/cups,g'

SUBST_CLASSES+=			fix-paths-2
SUBST_STAGE.fix-paths-2=	post-configure
SUBST_MESSAGE.fix-paths-2=	Fixing additional paths in installer/core_install.py.
SUBST_FILES.fix-paths-2=	installer/core_install.py
SUBST_SED.fix-paths-2=	-e 's,"/etc/PolicyKit,"${PKG_SYSCONFDIR}/PolicyKit,g'
SUBST_SED.fix-paths-2+=	-e 's,"/etc/polkit-1,"${PKG_SYSCONFDIR}/polkit-1,g'
SUBST_SED.fix-paths-2+=	-e 's,"file:///etc/hp,"file://${PKG_SYSCONFDIR}/hp,g'
SUBST_SED.fix-paths-2+=	-e 's,"/usr/lib/cups/driver,"${PREFIX}/libexec/cups/driver,g'
SUBST_SED.fix-paths-2+=	-e 's,\([ '\''"=]\)/usr,\1${PREFIX},g'

SUBST_CLASSES+=			fix-paths-3
SUBST_STAGE.fix-paths-3=	post-configure
SUBST_MESSAGE.fix-paths-3=	Fixing additional paths in base/pkit.py.
SUBST_FILES.fix-paths-3=	base/pkit.py
SUBST_SED.fix-paths-3=	-e 's,\([ '\''"=]\)/usr,\1${PREFIX},g'

SUBST_CLASSES+=			fix-paths-4
SUBST_STAGE.fix-paths-4=	post-configure
SUBST_MESSAGE.fix-paths-4=	Fixing default PPD search path in base/g.py and prnt/cups.py.
SUBST_FILES.fix-paths-4=	base/g.py prnt/cups.py
SUBST_SED.fix-paths-4=	-e '\,ppd_search_path =, { s,/usr/\([a-z]*\);,/usr/\1;${PREFIX}/\1;,g ; }'
SUBST_SED.fix-paths-4+=	-e 's,\([ '\''"=]\)/usr/share/ppd,\1${PREFIX}/share/ppd,g'

SUBST_CLASSES+=			fix-paths-5
SUBST_STAGE.fix-paths-5=	post-configure
SUBST_MESSAGE.fix-paths-5=	Fixing paths in prnt/hpijs/foomatic-rip-hplip.
SUBST_FILES.fix-paths-5=	prnt/hpijs/foomatic-rip-hplip
SUBST_SED.fix-paths-5=	-e 's,\([ '\''"=]\)/etc/cups,\1${PKG_SYSCONFDIR}/cups,g'
SUBST_SED.fix-paths-5+=	-e 's,\([ '\''"=]\)/etc/foomatic,\1${PKG_SYSCONFDIR}/foomatic,g'
SUBST_SED.fix-paths-5+=	-e 's,\([ '\''"=]\)/var/spool,\1${VARBASE}/spool,g'
SUBST_SED.fix-paths-5+=	-e 's,prefix = "/usr",prefix = "${PREFIX}",g'
SUBST_SED.fix-paths-5+=	-e 's,\(path = "/usr/bin:\),\1${PREFIX}/bin:,g'
SUBST_SED.fix-paths-5+=	-e 's,\(path = "/usr/lib/cups/filter:\),\1${PREFIX}/libexec/cups/filter:,g'
SUBST_SED.fix-paths-5+=	-e '\,} elsif (-r "/usr/share/ppr, { N ; p ; s,"/usr,"${PREFIX},g ; }'

SUBST_CLASSES+=			fix-paths-6
SUBST_STAGE.fix-paths-6=	post-configure
SUBST_MESSAGE.fix-paths-6=	Fixing paths in fax/filters/pstotiff.
SUBST_FILES.fix-paths-6=	fax/filters/pstotiff
SUBST_SED.fix-paths-6=	-e 's,"-I/usr/share/cups/fonts","-I${PREFIX}/share/cups/fonts",g'
SUBST_SED.fix-paths-6+=	-e 's,"/usr/bin/gs","${PREFIX}/bin/gs",g'

# NetBSD has strnlen(3) since 5.99.12
.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M5.99.*) && empty(OS_VERSION:M[6-9].*)
SUBST_CLASSES+=			fix-strnlen
SUBST_STAGE.fix-strnlen=	post-configure
SUBST_MESSAGE.fix-strnlen=	Replacing strnlen() with strlen() in two C++ files.
SUBST_FILES.fix-strnlen=	prnt/hpijs/context2.cpp prnt/hpijs/ljzjscolor.cpp
SUBST_SED.fix-strnlen=	-e 's/\([ (]\)strnlen(\([^,]*\), DevIDBuffSize)/\1strlen(\2)/g'
.endif

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

pre-configure:
	cd ${WRKSRC} && aclocal && automake --add-missing --foreign && autoconf

INSTALLATION_DIRS+=	share/cups/model

post-install:
	${CHMOD} a-x ${DESTDIR}${PREFIX}/share/hplip/__init__.py
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/share/hplip
	${LN} -s ../../../share/hplip/ppd ${DESTDIR}${PREFIX}/share/cups/model/hplip-ppds

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../print/ghostscript/ghostscript.buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
