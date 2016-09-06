#!@SH@
exec @PREFIX@/lib/sickbeard/SickBeard.py \
	--datadir=@VARBASE@/sickbeard \
	--pidfile=/var/run/sickbeard.pid \
	"$@"
