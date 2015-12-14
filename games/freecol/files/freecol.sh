#!/bin/sh
java -Xmx512M -jar @PREFIX@/share/freecol/FreeCol.jar --freecol-data @PREFIX@/share/freecol/data "$@"
