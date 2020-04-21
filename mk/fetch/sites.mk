# $NetBSD: sites.mk,v 1.164 2020/04/21 23:00:14 mef Exp $
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
	ftp://ftp.lip6.fr/pub/gnu/ \
	http://mirrors.kernel.org/gnu/ \
	ftp://ftp.funet.fi/pub/gnu/prep/ \
	http://ftp.gnu.org/pub/gnu/

MASTER_SITE_GITHUB+=    \
	https://github.com/

MASTER_SITE_GNUSTEP+=   \
	ftp://ftp.gnustep.org/pub/gnustep/

MASTER_SITE_OSDN+=	\
	http://jaist.dl.osdn.jp/ \
	http://iij.dl.osdn.jp/ \
	http://tcpdiag.dl.osdn.jp/ \
	http://c3sl.dl.osdn.jp/ \
	http://cznic.dl.osdn.jp/ \
	http://onet.dl.osdn.jp/ \
	http://nchc.dl.osdn.jp/ \
	http://rwthaachen.dl.osdn.jp/ \
	http://giganet.dl.osdn.jp/ \
	http://osdn.dl.osdn.jp/

MASTER_SITE_PERL_CPAN+= \
	https://cpan.perl.org/CPAN/modules/by-module/ \
	ftp://cpan.pair.com/modules/by-module/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/ \
	ftp://ftp.fi.muni.cz/pub/CPAN/modules/by-module/

MASTER_SITE_R_CRAN+=    \
	http://cran.r-project.org/src/ \
	ftp://cran.r-project.org/pub/R/src/ \
	http://cran.at.r-project.org/src/ \
	ftp://cran.at.r-project.org/pub/R/src/ \
	http://cran.ch.r-project.org/src/ \
	http://cran.uk.r-project.org/src/ \
	http://cran.us.r-project.org/src/ \
	http://lib.stat.cmu.edu/R/CRAN/src/ \
	ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/ \
	http://stat.ethz.ch/CRAN/src/ \
	http://www.stats.bris.ac.uk/R/src/

MASTER_SITE_TEX_CTAN+= \
	ftp://ftp.funet.fi/pub/TeX/CTAN/ \
	ftp://ftp.dante.de/tex-archive/ \
	ftp://www.dnsbalance.ring.gr.jp/pub/text/CTAN/ \
	http://www.dnsbalance.ring.gr.jp/archives/text/CTAN/

MASTER_SITE_SUNSITE+=   \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/ \
	ftp://ftp.lip6.fr/pub/linux/sunsite/

MASTER_SITE_GNOME+=     \
	http://ftp.gnome.org/pub/GNOME/ \
	ftp://ftp.gnome.org/pub/GNOME/ \
	https://download.gnome.org/

MASTER_SITE_KDE+=	\
	http://download.kde.org/stable/ \
	ftp://www.dnsbalance.ring.gr.jp/pub/X/kde/stable/ \
	http://www.dnsbalance.ring.gr.jp/archives/X/kde/stable/ \
	ftp://ftp.gtlib.gatech.edu/pub/kde/stable/ \
	ftp://kde.mirrors.tds.net/pub/kde/stable/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.kde.org/pub/kde/stable/ \
	ftp://mirrors.dotsrc.org/kde/stable/ \
	ftp://ftp.fi.muni.cz/pub/kde/stable/

MASTER_SITE_SOURCEFORGE+=	\
	http://downloads.sourceforge.net/sourceforge/

MASTER_SITE_SUSE+=	\
	ftp://rpmfind.net/linux/opensuse/update/${SUSE_VERSION}/${MACHINE_ARCH}/ \
	ftp://fr.rpmfind.net/linux/opensuse/update/${SUSE_VERSION}/${MACHINE_ARCH}/ \
	ftp://fr2.rpmfind.net/linux/opensuse/update/${SUSE_VERSION}/${MACHINE_ARCH}/

MASTER_SITE_MOZILLA_ALL+=   \
	http://download-origin.cdn.mozilla.net/pub/mozilla.org/ \
	http://ftp.mozilla.org/pub/mozilla.org/

# see http://www.mozilla.org/mirrors.html
MASTER_SITE_MOZILLA+=	\
	http://releases.mozilla.org/pub/mozilla.org/ \
	http://download-origin.cdn.mozilla.net/pub/mozilla.org/

MASTER_SITE_XEMACS+=    \
	ftp://ftp.xemacs.org/pub/xemacs/ \
	http://ftp.xemacs.org/ \
	http://ftp.de.xemacs.org/pub/ftp.xemacs.org/tux/xemacs/ \
	ftp://ftp.heanet.ie/mirrors/ftp.xemacs.org/ \
	http://ftp.heanet.ie/mirrors/ftp.xemacs.org/ \
	http://ftp.pt.xemacs.org/ \
	ftp://ftp.uk.xemacs.org/sites/ftp.xemacs.org/pub/xemacs/ \
	http://ftp.uk.xemacs.org/sites/ftp.xemacs.org/pub/xemacs/ \
	ftp://ftp.isr.tecnico.ulisboa.pt/pub/xemacs/ \
	http://ftp.isr.tecnico.ulisboa.pt/pub/xemacs/ \
	ftp://ftp.dnsbalance.ring.gr.jp/pub/text/xemacs/

# http://www.ibiblio.org/pub/mirrors/apache/ returns 200 for missing
# files, which is incompatible with resuming transfers.
MASTER_SITE_APACHE+=    \
	http://www.apache.org/dist/ \
	http://www.eu.apache.org/dist/ \
	http://apache.oregonstate.edu/ \
	http://apache.mirrors.tds.net/ \
	http://ftp.unicamp.br/pub/apache/ \
	http://www.mirrorservice.org/sites/ftp.apache.org/ \
	http://www.meisei-u.ac.jp/mirror/apache/dist/ \
	http://ftp.twaren.net/Unix/Web/apache/ \
	http://ftp.cuhk.edu.hk/pub/packages/apache.org/ \
	ftp://ftp.oregonstate.edu/pub/apache/ \
	ftp://apache.mirrors.tds.net/pub/apache.org/ \
	ftp://ftp.mirrorservice.org/sites/ftp.apache.org/ \
	ftp://ftp.meisei-u.ac.jp/pub/www/apache/dist/ \
	ftp://ftp.twaren.net/Unix/Web/apache/

MASTER_SITE_MYSQL+=	\
	http://mysql.mirror.kangaroot.net/Downloads/ \
	http://mysql.linux.cz/Downloads/ \
	ftp://ftp.fi.muni.cz/pub/mysql/Downloads/ \
	http://mirrors.dotsrc.org/mysql/Downloads/ \
	ftp://mirrors.dotsrc.org/mysql/Downloads/ \
	http://mirrors.ircam.fr/pub/mysql/Downloads/ \
	ftp://mirrors.ircam.fr/pub/mysql/Downloads/ \
	http://ftp.gwdg.de/pub/misc/mysql/Downloads/ \
	ftp://ftp.gwdg.de/pub/misc/mysql/Downloads/ \
	http://sunsite.informatik.rwth-aachen.de/mysql/Downloads/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/www.mysql.com/Downloads/ \
	ftp://ftp.fu-berlin.de/unix/databases/mysql/Downloads/ \
	http://ftp.ntua.gr/pub/databases/mysql/Downloads/ \
	ftp://ftp.ntua.gr/pub/databases/mysql/Downloads/ \
	http://mysql.mirrors.crysys.hit.bme.hu/Downloads/ \
	ftp://ftp.crysys.hu/pub/mysql/Downloads/ \
	http://ftp.heanet.ie/mirrors/www.mysql.com/Downloads/ \
	ftp://ftp.heanet.ie/mirrors/www.mysql.com/Downloads/ \
	http://na.mirror.garr.it/mirrors/MySQL/Downloads/ \
	http://mirrors.xservers.ro/mysql/Downloads/ \
	http://mysql.infocom.ua/Downloads/ \
	http://mirrors.dedipower.com/www.mysql.com/Downloads/ \
	http://www.mirrorservice.org/sites/ftp.mysql.com/Downloads/ \
	ftp://ftp.mirrorservice.org/sites/ftp.mysql.com/Downloads/ \
	http://mirror.csclub.uwaterloo.ca/mysql/Downloads/ \
	ftp://mirror.csclub.uwaterloo.ca/mysql/Downloads/ \
	http://mirror.trouble-free.net/mysql_mirror/Downloads/ \
	http://mysql.he.net/Downloads/ \
	http://mysql.mirrors.arminco.com/Downloads/ \
	http://mysql.spd.co.il/Downloads/ \
	http://ftp.iij.ad.jp/pub/db/mysql/Downloads/ \
	ftp://ftp.iij.ad.jp/pub/db/mysql/Downloads/ \
	ftp://mysql.cdpa.nsysu.edu.tw/Unix/Database/MySQL/Downloads/ \
	http://mirror-fpt-telecom.fpt.net/mysql/Downloads/ \
	http://mysql.mirror.ac.za/Downloads/ \
	http://mysql.inspire.net.nz/Downloads/ \
	ftp://mysql.inspire.net.nz/mysql/Downloads/

MASTER_SITE_DEBIAN+= \
	http://ftp.debian.org/debian/ \
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
	ftp://ftp.ussg.iu.edu/pub/openoffice/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/OpenOffice/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.openoffice.org/ \
	http://ftp.ntua.gr/pub/OpenOffice/ \
	http://na.mirror.garr.it/mirrors/openoffice/ \
	http://vlaai.snt.utwente.nl/pub/software/openoffice/ \
	ftp://ftp.dnsbalance.ring.gr.jp/pub/misc/openoffice/ \
	ftp://ftp.kr.freebsd.org/pub/openoffice/

MASTER_SITE_CYGWIN+= \
	http://mirrors.kernel.org/sources.redhat.com/cygwin/ \
	http://mirrors.xmission.com/cygwin/ \
	ftp://ftp.dnsbalance.ring.gr.jp/pub/pc/gnu-win32/ \
	ftp://ftp.funet.fi/pub/mirrors/cygwin.com/pub/cygwin/

MASTER_SITE_IFARCHIVE+= \
	http://ifarchive.flavorplex.com/if-archive/ \
	http://ifarchive.heanet.ie/if-archive/ \
	ftp://ftp.giga.or.at/pub/ifarchive/

MASTER_SITE_PGSQL+=	\
	http://ftp.postgresql.org/pub/

MASTER_SITE_GENTOO+= \
	http://ftp-stud.fht-esslingen.de/pub/Mirrors/gentoo/ \
	http://ftp.heanet.ie/pub/gentoo/ \
	http://mirror.bytemark.co.uk/gentoo/ \
	http://gentoo.mirror.dkm.cz/pub/gentoo/ \
	http://ftp.ds.karen.hj.se/gentoo/ \
	ftp://ftp.free.fr/mirrors/ftp.gentoo.org/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/Linux/gentoo/ \
	http://gentoo-euetib.upc.es/mirror/gentoo/ \
	http://ftp.ntua.gr/pub/linux/gentoo/ \
	http://www.las.ic.unicamp.br/pub/gentoo/ \
	http://mirror.yandex.ru/gentoo-distfiles/ \
	http://ftp.swin.edu.au/gentoo/ \
	http://ftp.iij.ad.jp/pub/linux/gentoo/ \
	http://ftp.jaist.ac.jp/pub/Linux/Gentoo/ \
	http://distfiles.gentoo.org/

MASTER_SITE_XORG+= \
	http://xorg.freedesktop.org/releases/individual/ \
	ftp://ftp.x.org/pub/individual/

MASTER_SITE_FREEBSD+= \
	http://distcache.FreeBSD.org/ports-distfiles/

MASTER_SITE_FREEBSD_LOCAL+= \
	http://distcache.FreeBSD.org/local-distfiles/

MASTER_SITE_NETLIB+= \
	http://netlib.org/ \
	http://netlib.sandia.gov/ \
	http://www.mirrorservice.org/sites/netlib.bell-labs.com/netlib/

MASTER_SITE_OPENBSD+= \
	http://ftp.OpenBSD.org/pub/OpenBSD/ \
	ftp://ftp3.usa.openbsd.org/pub/OpenBSD/ \
	ftp://ftp.jaist.ac.jp/pub/OpenBSD/

MASTER_SITE_RUBYGEMS+= \
	https://rubygems.org/gems/

MASTER_SITE_PYPI+= \
	https://files.pythonhosted.org/packages/source/

MASTER_SITE_HASKELL_HACKAGE+=	\
	http://hackage.haskell.org/package/

MASTER_SITE_CRATESIO+=	\
	https://crates.io/api/v1/crates/

# The primary backup site.
MASTER_SITE_BACKUP?=	\
	http://cdn.NetBSD.org/pub/pkgsrc/distfiles/ \
	http://ftp6.NetBSD.org/pub/pkgsrc/distfiles/ \
	http://ftp.fr.NetBSD.org/pub/pkgsrc/distfiles/ \
	http://ftp.NetBSD.org/pub/pkgsrc/distfiles/
