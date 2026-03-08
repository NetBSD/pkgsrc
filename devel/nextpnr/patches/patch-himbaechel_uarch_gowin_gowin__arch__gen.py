$NetBSD: patch-himbaechel_uarch_gowin_gowin__arch__gen.py,v 1.1 2026/03/08 12:45:35 ryoon Exp $

* From 06ae973aa8dbe116ddf0bc94b234cd421a7f118a.

--- himbaechel/uarch/gowin/gowin_arch_gen.py.orig	2025-09-05 07:02:19.000000000 +0000
+++ himbaechel/uarch/gowin/gowin_arch_gen.py
@@ -2,7 +2,6 @@ import importlib.resources
 import sys
 
 import importlib.resources
-import pickle
 import gzip
 import re
 import argparse
@@ -10,6 +9,7 @@ from apycula import chipdb
 sys.path.append(path.join(path.dirname(__file__), "../.."))
 from himbaechel_dbgen.chip import *
 from apycula import chipdb
+from apycula.chipdb import load_chipdb
 
 # Bel flags
 BEL_FLAG_SIMPLE_IO = 0x100
@@ -506,7 +506,7 @@ def create_switch_matrix(tt: TileType, db: chipdb, x: 
             return "LW_TAP"
         return ""
 
-    for dst, srcs in db.grid[y][x].pips.items():
+    for dst, srcs in db[y, x].pips.items():
         if not tt.has_wire(dst):
             tt.create_wire(dst, get_wire_type(dst))
         for src in srcs.keys():
@@ -520,7 +520,7 @@ def create_switch_matrix(tt: TileType, db: chipdb, x: 
             tt.create_pip(src, dst, get_tm_class(db, src))
 
     # clock wires
-    for dst, srcs in db.grid[y][x].clock_pips.items():
+    for dst, srcs in db[y, x].clock_pips.items():
         if not tt.has_wire(dst):
             tt.create_wire(dst, "GLOBAL_CLK")
         for src in srcs.keys():
@@ -552,7 +552,7 @@ def create_hclk_switch_matrix(tt: TileType, db: chipdb
         "CLKDIV_HCLK1_SECT1": CLKDIV_3_Z
     }
 
-    for bel_name, bel_props in db.grid[y][x].bels.items():
+    for bel_name, bel_props in db[y, x].bels.items():
         if (bel_name not in hclk_bel_zs):
             continue
         this_portmap = bel_props.portmap
@@ -599,7 +599,7 @@ def create_extra_funcs(tt: TileType, db: chipdb, x: in
     for func, desc in db.extra_func[(y, x)].items():
         if func == 'osc':
             osc_type = desc['type']
-            portmap = db.grid[y][x].bels[osc_type].portmap
+            portmap = db[y, x].bels[osc_type].portmap
             for port, wire in portmap.items():
                 if not tt.has_wire(wire):
                     tt.create_wire(wire, port)
@@ -695,7 +695,7 @@ def create_extra_funcs(tt: TileType, db: chipdb, x: in
 
             for io_type, z in {('IDES16', IDES16_Z), ('OSER16', OSER16_Z)}:
                 bel = tt.create_bel(io_type, io_type, z = z)
-                portmap = db.grid[y][x].bels[io_type].portmap
+                portmap = db[y, x].bels[io_type].portmap
                 for port, wire in portmap.items():
                     if port == 'FCLK': # XXX compatibility
                         wire = 'FCLKA'
@@ -893,10 +893,10 @@ def create_io_tiletype(chip: Chip, db: chipdb, x: int,
     for i in range(rng):
         name = 'IOB' + 'ABCDEFGHIJ'[i]
         # XXX some IOBs excluded from generic chipdb for some reason
-        if name not in db.grid[y][x].bels:
+        if name not in db[y, x].bels:
             continue
         # wires
-        portmap = db.grid[y][x].bels[name].portmap
+        portmap = db[y, x].bels[name].portmap
         tt.create_wire(portmap['I'], "IO_I")
         tt.create_wire(portmap['O'], "IO_O")
         tt.create_wire(portmap['OE'], "IO_OE")
@@ -916,11 +916,11 @@ def create_io_tiletype(chip: Chip, db: chipdb, x: int,
             tt.add_bel_pin(io, "BOTTOM_IO_PORT_B", portmap['BOTTOM_IO_PORT_B'], PinType.INPUT)
     # create IOLOGIC bels if any
     for idx, name in {(IOLOGICA_Z, 'IOLOGICA'), (IOLOGICA_Z + 1, 'IOLOGICB')}:
-        if name not in db.grid[y][x].bels:
+        if name not in db[y, x].bels:
             continue
         for off, io_type in {(0, 'O'), (2, 'I')}:
             iol = tt.create_bel(f"{name}{io_type}", f"IOLOGIC{io_type}", z = idx + off)
-            for port, wire in db.grid[y][x].bels[name].portmap.items():
+            for port, wire in db[y, x].bels[name].portmap.items():
                 if port == 'FCLK': # XXX compatibility
                     wire = f'FCLK{name[-1]}'
                 if not tt.has_wire(wire):
@@ -1073,7 +1073,7 @@ def create_bsram_tiletype(chip: Chip, db: chipdb, x: i
     tt = chip.create_tile_type(tiletype)
     tt.extra_data = TileExtraData(chip.strs.id(typename))
 
-    portmap = db.grid[y][x].bels['BSRAM'].portmap
+    portmap = db[y, x].bels['BSRAM'].portmap
     bsram = tt.create_bel("BSRAM", "BSRAM", z = BSRAM_Z)
 
 
@@ -1107,21 +1107,21 @@ def create_dsp_tiletype(chip: Chip, db: chipdb, x: int
 
     # create big DSP
     belname = f'DSP'
-    portmap = db.grid[y][x].bels[belname].portmap
+    portmap = db[y, x].bels[belname].portmap
     dsp = tt.create_bel(belname, "DSP", DSP_Z)
     dsp.flags = BEL_FLAG_HIDDEN
 
     # create DSP macros
     for idx in range(2):
         belname = f'DSP{idx}'
-        portmap = db.grid[y][x].bels[belname].portmap
+        portmap = db[y, x].bels[belname].portmap
         dsp = tt.create_bel(belname, "DSP", eval(f'DSP_{idx}_Z'))
         dsp.flags = BEL_FLAG_HIDDEN
 
     # create pre-adders
     for mac, idx in [(mac, idx) for mac in range(2) for idx in range(4)]:
         belname = f'PADD9{mac}{idx}'
-        portmap = db.grid[y][x].bels[belname].portmap
+        portmap = db[y, x].bels[belname].portmap
         dsp = tt.create_bel(belname, "PADD9", eval(f'PADD9_{mac}_{idx}_Z'))
 
         add_port_wire(tt, dsp, portmap, "ADDSUB", "DSP_I", PinType.INPUT)
@@ -1140,7 +1140,7 @@ def create_dsp_tiletype(chip: Chip, db: chipdb, x: int
 
     for mac, idx in [(mac, idx) for mac in range(2) for idx in range(2)]:
         belname = f'PADD18{mac}{idx}'
-        portmap = db.grid[y][x].bels[belname].portmap
+        portmap = db[y, x].bels[belname].portmap
         dsp = tt.create_bel(belname, "PADD18", eval(f'PADD18_{mac}_{idx}_Z'))
 
         add_port_wire(tt, dsp, portmap, "ADDSUB", "DSP_I", PinType.INPUT)
@@ -1161,7 +1161,7 @@ def create_dsp_tiletype(chip: Chip, db: chipdb, x: int
     # mult 9x9
     for mac, idx in [(mac, idx) for mac in range(2) for idx in range(4)]:
         belname = f'MULT9X9{mac}{idx}'
-        portmap = db.grid[y][x].bels[belname].portmap
+        portmap = db[y, x].bels[belname].portmap
         dsp = tt.create_bel(belname, "MULT9X9", eval(f'MULT9X9_{mac}_{idx}_Z'))
 
         for sfx in {'A', 'B'}:
@@ -1179,7 +1179,7 @@ def create_dsp_tiletype(chip: Chip, db: chipdb, x: int
     # mult 18x18
     for mac, idx in [(mac, idx) for mac in range(2) for idx in range(2)]:
         belname = f'MULT18X18{mac}{idx}'
-        portmap = db.grid[y][x].bels[belname].portmap
+        portmap = db[y, x].bels[belname].portmap
         dsp = tt.create_bel(belname, "MULT18X18", eval(f'MULT18X18_{mac}_{idx}_Z'))
 
         for sfx in {'A', 'B'}:
@@ -1196,14 +1196,14 @@ def create_dsp_tiletype(chip: Chip, db: chipdb, x: int
 
     # mult 36x36
     belname = 'MULT36X36'
-    portmap = db.grid[y][x].bels[belname].portmap
+    portmap = db[y, x].bels[belname].portmap
     dsp = tt.create_bel(belname, "MULT36X36", MULT36X36_Z)
 
     # LSB 18x18 multipliers sign ports must be zero
-    add_port_wire(tt, dsp, db.grid[y][x].bels['MULT18X1800'].portmap, 'ASIGN', "DSP_I", PinType.INPUT, 'ZERO_ASIGN0')
-    add_port_wire(tt, dsp, db.grid[y][x].bels['MULT18X1800'].portmap, 'BSIGN', "DSP_I", PinType.INPUT, 'ZERO_BSIGN0')
-    add_port_wire(tt, dsp, db.grid[y][x].bels['MULT18X1801'].portmap, 'BSIGN', "DSP_I", PinType.INPUT, 'ZERO_BSIGN1')
-    add_port_wire(tt, dsp, db.grid[y][x].bels['MULT18X1810'].portmap, 'ASIGN', "DSP_I", PinType.INPUT, 'ZERO_ASIGN1')
+    add_port_wire(tt, dsp, db[y, x].bels['MULT18X1800'].portmap, 'ASIGN', "DSP_I", PinType.INPUT, 'ZERO_ASIGN0')
+    add_port_wire(tt, dsp, db[y, x].bels['MULT18X1800'].portmap, 'BSIGN', "DSP_I", PinType.INPUT, 'ZERO_BSIGN0')
+    add_port_wire(tt, dsp, db[y, x].bels['MULT18X1801'].portmap, 'BSIGN', "DSP_I", PinType.INPUT, 'ZERO_BSIGN1')
+    add_port_wire(tt, dsp, db[y, x].bels['MULT18X1810'].portmap, 'ASIGN', "DSP_I", PinType.INPUT, 'ZERO_ASIGN1')
     for i in range(2):
         for sfx in {'A', 'B'}:
             for inp in range(36):
@@ -1220,7 +1220,7 @@ def create_dsp_tiletype(chip: Chip, db: chipdb, x: int
     # create alus
     for mac in range(2):
         belname = f'ALU54D{mac}'
-        portmap = db.grid[y][x].bels[belname].portmap
+        portmap = db[y, x].bels[belname].portmap
         dsp = tt.create_bel(belname, "ALU54D", eval(f'ALU54D_{mac}_Z'))
 
         for sfx in {'A', 'B'}:
@@ -1241,7 +1241,7 @@ def create_dsp_tiletype(chip: Chip, db: chipdb, x: int
     # MULTALU18X18
     for mac in range(2):
         belname = f'MULTALU18X18{mac}'
-        portmap = db.grid[y][x].bels[belname].portmap
+        portmap = db[y, x].bels[belname].portmap
         dsp = tt.create_bel(belname, "MULTALU18X18", eval(f'MULTALU18X18_{mac}_Z'))
 
         for i in range(2):
@@ -1266,7 +1266,7 @@ def create_dsp_tiletype(chip: Chip, db: chipdb, x: int
     # MULTALU36X18
     for mac in range(2):
         belname = f'MULTALU36X18{mac}'
-        portmap = db.grid[y][x].bels[belname].portmap
+        portmap = db[y, x].bels[belname].portmap
         dsp = tt.create_bel(belname, "MULTALU36X18", eval(f'MULTALU36X18_{mac}_Z'))
 
         for i in range(2):
@@ -1290,7 +1290,7 @@ def create_dsp_tiletype(chip: Chip, db: chipdb, x: int
     # MULTADDALU18X18
     for mac in range(2):
         belname = f'MULTADDALU18X18{mac}'
-        portmap = db.grid[y][x].bels[belname].portmap
+        portmap = db[y, x].bels[belname].portmap
         dsp = tt.create_bel(belname, "MULTADDALU18X18", eval(f'MULTADDALU18X18_{mac}_Z'))
 
         for i in range(2):
@@ -1345,7 +1345,7 @@ def create_pll_tiletype(chip: Chip, db: chipdb, x: int
     else:
         pll_name = 'RPLLA'
         bel_type = 'rPLL'
-    portmap = db.grid[y][x].bels[pll_name].portmap
+    portmap = db[y, x].bels[pll_name].portmap
     pll = tt.create_bel("PLL", bel_type, z = PLL_Z)
     pll.flags = BEL_FLAG_GLOBAL
     for pin, wire in portmap.items():
@@ -1576,8 +1576,8 @@ def main():
     args = parser.parse_args()
 
     device = args.device
-    with gzip.open(importlib.resources.files("apycula").joinpath(f"{device}.pickle"), 'rb') as f:
-        db = pickle.load(f)
+    with importlib.resources.as_file(importlib.resources.files("apycula").joinpath(f"{device}.msgpack.xz")) as chipdb_path:
+        db = load_chipdb(chipdb_path)
 
     chip_flags = 0;
     # XXX compatibility
@@ -1630,7 +1630,7 @@ def main():
     # Setup tile grid
     for x in range(X):
         for y in range(Y):
-            ttyp = db.grid[y][x].ttyp
+            ttyp = db.grid[y][x]
             if (x == 0 or x == X - 1) and (y == 0 or y == Y - 1):
                 assert ttyp not in created_tiletypes, "Duplication of corner types"
                 create_tiletype(create_corner_tiletype, ch, db, x, y, ttyp)
