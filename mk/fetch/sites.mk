# $NetBSD: sites.mk,v 1.192 2023/12/29 00:14:04 zafer Exp $
#
# This Makefile fragment defines read-only MASTER_SITE_* variables
# representing some well-known master distribution sites for software.
#
# These variables are also listed in the pkgsrc guide.

MASTER_SITE_XCONTRIB+=  \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/ \
	ftp://sunsite.icm.edu.pl/pub/X11/contrib/ \
	ftp://ftp.x.org/contrib/

MASTER_SITE_GNU+=       \
	https://mirrors.dotsrc.org/gnu/ \
	https://ftp.nluug.nl/pub/gnu/ \
	https://mirrors.kernel.org/gnu/ \
	https://ftp.funet.fi/pub/gnu/prep/ \
	https://ftp.gnu.org/pub/gnu/

MASTER_SITE_GITHUB+=    \
	https://github.com/

MASTER_SITE_GITLAB+=	\
	https://gitlab.com/

MASTER_SITE_GNUSTEP+=   \
	ftp://ftp.gnustep.org/pub/gnustep/

MASTER_SITE_OSDN+=	\
	http://jaist.dl.osdn.jp/ \
	http://iij.dl.osdn.jp/ \
	http://c3sl.dl.osdn.jp/ \
	http://onet.dl.osdn.jp/ \
	http://nchc.dl.osdn.jp/ \
	http://osdn.dl.osdn.jp/

MASTER_SITE_PERL_CPAN+= \
	https://www.cpan.org/modules/by-module/ \
	https://cpan.pair.com/modules/by-module/ \
	https://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/ \
	ftp://ftp.fi.muni.cz/pub/CPAN/modules/by-module/

MASTER_SITE_R_CRAN+=    \
	https://cran.r-project.org/src/ \
	http://lib.stat.cmu.edu/R/CRAN/src/ \
	https://stat.ethz.ch/CRAN/src/ \
	https://www.stats.bris.ac.uk/R/src/

MASTER_SITE_TEX_CTAN+= \
	https://ftp.funet.fi/pub/TeX/CTAN/ \
	ftp://www.dnsbalance.ring.gr.jp/pub/text/CTAN/ \
	http://www.dnsbalance.ring.gr.jp/archives/text/CTAN/

MASTER_SITE_SUNSITE+=   \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/

MASTER_SITE_GNOME+=     \
	https://download.gnome.org/

MASTER_SITE_KDE+=	\
	https://download.kde.org/stable/ \
	ftp://www.dnsbalance.ring.gr.jp/pub/X/kde/stable/ \
	http://www.dnsbalance.ring.gr.jp/archives/X/kde/stable/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.kde.org/pub/kde/stable/ \
	ftp://mirrors.dotsrc.org/kde/stable/ \
	ftp://ftp.fi.muni.cz/pub/kde/stable/

MASTER_SITE_SOURCEFORGE+=	\
	https://downloads.sourceforge.net/sourceforge/

MASTER_SITE_SUSE+=	\
	ftp://rpmfind.net/linux/opensuse/update/${SUSE_VERSION}/${MACHINE_ARCH}/ \
	ftp://fr.rpmfind.net/linux/opensuse/update/${SUSE_VERSION}/${MACHINE_ARCH}/ \
	ftp://fr2.rpmfind.net/linux/opensuse/update/${SUSE_VERSION}/${MACHINE_ARCH}/

MASTER_SITE_MOZILLA_ALL+=   \
	https://download-origin.cdn.mozilla.net/pub/ \
	https://ftp.mozilla.org/pub/

# see http://www.mozilla.org/mirrors.html
MASTER_SITE_MOZILLA+=	\
	https://releases.mozilla.org/pub/ \
	https://download-origin.cdn.mozilla.net/pub/

MASTER_SITE_XEMACS+=    \
	ftp://ftp.xemacs.org/pub/xemacs/ \
	http://ftp.xemacs.org/ \
	ftp://ftp.uk.xemacs.org/sites/ftp.xemacs.org/pub/xemacs/ \
	http://ftp.uk.xemacs.org/sites/ftp.xemacs.org/pub/xemacs/ \
	ftp://ftp.dnsbalance.ring.gr.jp/pub/text/xemacs/

MASTER_SITE_APACHE+=    \
	https://downloads.apache.org/ \
	https://archive.apache.org/dist/

MASTER_SITE_MYSQL+=	\
	https://mysql.linux.cz/Downloads/ \
	ftp://ftp.fi.muni.cz/pub/mysql/Downloads/ \
	https://mirrors.dotsrc.org/mysql/Downloads/ \
	ftp://mirrors.dotsrc.org/mysql/Downloads/ \
	https://ftp.gwdg.de/pub/misc/mysql/Downloads/ \
	ftp://ftp.gwdg.de/pub/misc/mysql/Downloads/ \
	ftp://ftp.fu-berlin.de/unix/databases/mysql/Downloads/ \
	https://www.mirrorservice.org/sites/ftp.mysql.com/Downloads/ \
	ftp://ftp.mirrorservice.org/sites/ftp.mysql.com/Downloads/ \
	https://mirror.csclub.uwaterloo.ca/mysql/Downloads/ \
	ftp://mirror.csclub.uwaterloo.ca/mysql/Downloads/ \
	https://ftp.iij.ad.jp/pub/db/mysql/Downloads/ \
	ftp://ftp.iij.ad.jp/pub/db/mysql/Downloads/

MASTER_SITE_DEBIAN+= \
	https://ftp.debian.org/debian/ \
	http://ftp.at.debian.org/debian/ \
	http://ftp.au.debian.org/debian/ \
	http://ftp.wa.au.debian.org/debian/ \
	http://ftp.bg.debian.org/debian/ \
	http://ftp.cl.debian.org/debian/ \
	http://ftp.cz.debian.org/debian/ \
	http://ftp.de.debian.org/debian/ \
	http://ftp2.de.debian.org/debian/ \
	http://ftp.ee.debian.org/debian/ \
	http://ftp.fi.debian.org/debian/ \
	http://ftp.fr.debian.org/debian/ \
	http://ftp2.fr.debian.org/debian/ \
	http://ftp.uk.debian.org/debian/ \
	http://ftp.hr.debian.org/debian/ \
	http://ftp.ie.debian.org/debian/ \
	http://ftp.is.debian.org/debian/ \
	http://ftp.it.debian.org/debian/ \
	http://ftp.jp.debian.org/debian/ \
	http://ftp.nl.debian.org/debian/ \
	http://ftp.no.debian.org/debian/ \
	http://ftp.nz.debian.org/debian/ \
	http://ftp.pl.debian.org/debian/ \
	http://ftp.ru.debian.org/debian/ \
	http://ftp.se.debian.org/debian/ \
	http://ftp.sk.debian.org/debian/ \
	http://ftp.us.debian.org/debian/

MASTER_SITE_OPENOFFICE+=	\
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.openoffice.org/

MASTER_SITE_CYGWIN+= \
	https://mirrors.kernel.org/sources.redhat.com/cygwin/ \
	https://mirrors.xmission.com/cygwin/ \
	ftp://ftp.dnsbalance.ring.gr.jp/pub/pc/gnu-win32/ \
	https://ftp.funet.fi/pub/mirrors/cygwin.com/pub/cygwin/

MASTER_SITE_IFARCHIVE+= \
	http://ifarchive.flavorplex.com/if-archive/

MASTER_SITE_PGSQL+=	\
	https://ftp.postgresql.org/pub/

MASTER_SITE_GENTOO+= \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/gentoo/ \
	https://mirror.bytemark.co.uk/gentoo/ \
	ftp://ftp.free.fr/mirrors/ftp.gentoo.org/ \
	http://ftp.ntua.gr/pub/linux/gentoo/ \
	https://mirror.yandex.ru/gentoo-distfiles/ \
	https://ftp.swin.edu.au/gentoo/ \
	https://ftp.iij.ad.jp/pub/linux/gentoo/ \
	https://ftp.jaist.ac.jp/pub/Linux/Gentoo/ \
	https://distfiles.gentoo.org/

MASTER_SITE_XORG+= \
	https://xorg.freedesktop.org/releases/individual/ \
	ftp://ftp.x.org/pub/individual/

MASTER_SITE_FREEBSD+= \
	http://distcache.FreeBSD.org/ports-distfiles/

MASTER_SITE_FREEBSD_LOCAL+= \
	http://distcache.FreeBSD.org/local-distfiles/

MASTER_SITE_NETLIB+= \
	https://netlib.org/ \
	https://netlib.sandia.gov/

MASTER_SITE_OPENBSD+= \
	https://ftp.OpenBSD.org/pub/OpenBSD/ \
	ftp://ftp3.usa.openbsd.org/pub/OpenBSD/ \
	ftp://ftp.jaist.ac.jp/pub/OpenBSD/

MASTER_SITE_RUBYGEMS+= \
	https://rubygems.org/gems/

MASTER_SITE_PYPI+= \
	https://files.pythonhosted.org/packages/source/

MASTER_SITE_HASKELL_HACKAGE+=	\
	https://hackage.haskell.org/package/

MASTER_SITE_CRATESIO+=	\
	https://crates.io/api/v1/crates/

# The primary backup site.
MASTER_SITE_BACKUP?=	\
	https://cdn.NetBSD.org/pub/pkgsrc/distfiles/ \
	http://ftp.fr.NetBSD.org/pub/pkgsrc/distfiles/ \
	https://ftp.NetBSD.org/pub/pkgsrc/distfiles/
